# 11-DAC

# 什么是DAC
Digital-to-Analog Converter的缩写。数模转换器。又称D/A转换器，简称DAC，是指将离散的数字信号转换为连续变量的模拟信号的器件。


典型的数字模拟转换器将表示一定比例电压值的数字信号转换为模拟信号。


STM32F1中有两个DAC,可以同时使用STM32的DAC模块是12位数字输入，电压输出型的DAC。


DAC 有两个用途：输出波形和输出固定电压


# ADC工作原理

## ADC工作框图

![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317144332.png)

分别有三个部分

## 触发方式

第一部分，触发方式，是指DAC转换可以由某外部事件触发（定时器计数器、外部中断线）。配置控制位TSELx[2:0]可以选择8个触发事件之一触发DAC转换，任意一种触发源都可以触发DAC转换。

![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317144411.png)

六个是定时器触发：TIM2，TIM4，TIM5，TIM6，TIM7和TIM8。剩下两个分别是：EXTI线路9(PC9)和软件触发

每次DAC接口侦测到来自选中的定时器TRGO输出，或者外部中断线9的上升沿，近存放在寄 存器DAC_DHRx中的数据会被传送到寄存器DAC_DORx中。在3个APB1时钟周期后，寄存器 DAC_DORx更新为新值。

如果选择软件触发，一旦SWTRIG位置’1’，转换即开始。在数据从DAC_DHRx寄存器传送到 DAC_DORx寄存器后，SWTRIG位由硬件自动清0；

## 控制逻辑

此部分决定了DAC的波形控制，输出方式，DMA传输，等等，

我们来具体讲解下，
从框图可以看出，DAC受DORx寄存器直接控制的，但是
数据并不是直接传入DORx的，需要先传入DHRx 之后在间接地传给DORx寄存器 不能直接往DORx寄存器写入数据

如果没有选择硬件触发（TENx=0），在一个APB1周期后传入DORx，
如果选择硬件触发（TENx=1），则在3个APB1周期后传入DORx
一旦数据从DAC_DHRx寄存器装入DAC_DORx寄存器，在经过时间Tsetting（大约3us） 之后，输出即有效，这段时间的长短依电源电压和模拟输出负载的不同会有所变化

![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317144608.png)

![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317144625.png)

上图的DMAENx TENx MAMOx[3:0],WAVENx[1:0]位 都是由DAC_CR寄存器控制的

DMAENx 控制DAC通道1/2 的DMA使能

MAMP2[3:0]：DAC通道2屏蔽/幅值选择器 位 27:24 由软件设置这些位，
用来在噪声生成模式下选择屏蔽位，在三角波生成模式下选择波形的幅值。

WAVE2[1:0]：DAC通道2噪声/三角波生成使能

位23:22

决定是否产生波形，和产生什么波形。
00：关闭波形发生器；
10：使能噪声波形发生器；
1x：使能三角波发生器。

TENx：DAC通道x触发使能，用来使能/关闭DAC通道x的触发。

0：关闭DAC通道x触发，写入DAC_DHRx寄存器的数据在1个APB1时钟周期后传入 DAC_DORx寄存器；
1：使能DAC通道x触发，写入DAC_DHRx寄存器的数据在3个APB1时钟周期后传入 DAC_DORx寄存器。
注意：如果选择软件触发，写入寄存器DAC_DHRx的数据只需要1个APB1时钟周期就可以传入 寄存器DAC_DORx。


## 数模转换器

VDDA和VSSA为DAC模块模拟部分的供电。
Vref+则是DAC模块的参考电压。
DAC_OUTx就是DAC的输出通道了（对应PA4或者PA5引脚）

从左边的参考电压Vref+ ---->数模转换器 ---->模拟信号输出引脚

![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317145257.png)

![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317145323.png)

注意：DAC的引脚应该设置成模拟输入(AIN)模式

DAC输出电压：

数字输入经过DAC被线性地转换为模拟电压输出

其范围为 0~VREF+

DAC输出 = VREF x (DOR/4095)

特殊功能：
噪声波形生成，三角波形生成，外部触发转换，双DAC同时或者分别转换；每个通道都有DMA功能；

参考电压：2.4V~ 3.3V

# DAC原理总结

数字/模拟转换模块(DAC)是12位数字输入，电压输出的数字/模拟转换器。DAC可以配置为8位或12位模式，也可以与DMA控制器配合使用。DAC工作在12位模式时，数据可以设置成左对齐或右对齐。DAC模块有2个输出通道，每个通道都有单独的转换器。在双DAC模式下，2个通道可以独立地进行转换，也可以同时进行转换并同步地更新2个通道的输出。DAC可以通过引脚输入参考电压VREF+ 以获得更精确的转换结果。


# CubeMX工程创建
1. Debug设置
![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317150034.png)
2. 设置RCC时钟
![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317150125.png)
3. 设置时钟源
![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317150223.png)
4. DAC设置
上面的输出选择both
![Img](/00-嵌入式软件工程师/03-STM32L475VET6/00-笔记/FILES/11-DAC.md/img-20230317155431.png)


# 主函数输出电压：

```C
  /* USER CODE BEGIN 2 */
  HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 2048);

	HAL_DAC_Start(&hdac,DAC_CHANNEL_1);
  /* USER CODE END 2 */

```

在main()主函数中设置DAC输出的数据为12位右对齐，DAC输出为2048，并使能DAC1输出通道

DAC输出 = VREF x (DOR/4095)

则实际输出的电压为
2048/4096x3.3V=1.65V，

可以使用万用表或者ADC来测量其电压。

HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 2048);
功能：设置DAC的输出值
参数一： DAC结构体名
参数二： 设置DAC通道
参数三： 设置DAC对齐方式
参数四： 设置输出电压值 12位最大位4095

HAL_DAC_Start(&hdac,DAC_CHANNEL_1);
功能：开启DAC输出
参数一： DAC结构体名
参数二： DAC通道


# DAC 库函数详解
```C

/* IO operation functions *****************************************************/
HAL_StatusTypeDef HAL_DAC_Start(DAC_HandleTypeDef* hdac, uint32_t Channel);     //开启DAC输出

HAL_StatusTypeDef HAL_DAC_Stop(DAC_HandleTypeDef* hdac, uint32_t Channel);   //关闭DAC输出

HAL_StatusTypeDef HAL_DAC_Start_DMA(DAC_HandleTypeDef* hdac, uint32_t Channel, uint32_t* pData, uint32_t Length, uint32_t Alignment); //需要函数中不断开启   //开启DAC的DMA输出

HAL_StatusTypeDef HAL_DAC_Stop_DMA(DAC_HandleTypeDef* hdac, uint32_t Channel); //关闭DAC的DMA输出

HAL_StatusTypeDef HAL_DAC_SetValue(DAC_HandleTypeDef* hdac, uint32_t Channel, uint32_t Alignment, uint32_t Data);  //设置DAC输出值

uint32_t HAL_DAC_GetValue(DAC_HandleTypeDef* hdac, uint32_t Channel);  //获取DAC输出值

```

























