# 初识RT_Thread

![Img](/00-嵌入式软件工程师/05-RT_Thread/02-RT_Thread官方入门教程/01-初识RT_Thread/FILES/初识RT_Thread.md/img-20230419203256.png)

![Img](/00-嵌入式软件工程师/05-RT_Thread/02-RT_Thread官方入门教程/01-初识RT_Thread/FILES/初识RT_Thread.md/img-20230419203304.png)


# 开发环境的准备

本系列视频基于RT——Thread3.1.0版内核，硬件平台为STM32F103XE，所有功能都可以通过仿真实现；

## MDK下载
+ 需要MDK5.14版本以上
+ 需要安装STM32F103芯片数据库：[点击此处下载](https://pan.baidu.com/s/1MKzo24RTxiJGcjTJBHxcqA?_at_=1681907777962#list/path=%2F&parentPath=%2Fsharelink4264488348-1100266334019330)
+ 需要下载示例代码：[RT-Thread Simulator](https://gitee.com/rtthread/docs-online/raw/master/rt-thread-version/rt-thread-standard/tutorial/quick-start/stm32f103-simulator/rtthread_simulator_v0.1.0.7z)，[内核示例代码](https://github.com/RT-Thread-packages/kernel-sample)


# 代码目录介绍

## RT_Thread
RT-Thread源码各目录大概内容如下：

RT-Thread Simulator解压完成之后，根目录下有一个文件夹rt-thread，这里面又有四个文件夹：
+ src：RTT的核心代码；
+ libcpu：对各种不同类型架构cpu芯片的支持文件；
+ include：RTT内核头文件；
+ components：RTT的各种组件（cplusplus–C++ API支持库，dfs–设备文件系统，
+ + drivers–设备驱动框架，
+ + finsh–命令行控制终端，
+ + libc–POSIX API支持库，
+ + net–网络协议栈及框架等）；


## 工程源码

![Img](/00-嵌入式软件工程师/05-RT_Thread/02-RT_Thread官方入门教程/01-初识RT_Thread/FILES/初识RT_Thread.md/img-20230419204813.png)

![Img](/00-嵌入式软件工程师/05-RT_Thread/02-RT_Thread官方入门教程/01-初识RT_Thread/FILES/初识RT_Thread.md/img-20230419204900.png)

## MDK工程目录
![Img](/00-嵌入式软件工程师/05-RT_Thread/02-RT_Thread官方入门教程/01-初识RT_Thread/FILES/初识RT_Thread.md/img-20230419205030.png)

对其进行编译，然后在debug环境下仿真运行，可以在uart1观察到输出，在命令行输入help可以看到帮助信息；
输入version可以查看版本信息，该功能支持自动补全



# RT_Thread的启动过程

使用单步运行模式可以看到：

初识启动之后：
```C
int $Sub$$main(void)
{
    rt_hw_interrupt_disable();
    rtthread_startup();
    return 0;
}

MDK 提供了扩展功能 $Sub$$ 和 $Super$$,
可以给 main 添加 $Sub$$ 的前缀符号作为一个新功能函数 $Sub$$main，
这个 $Sub$$main 可以先调用一些要补充在 main 之前的功能函数
（这里添加 RT-Thread 系统初始化功能），
再调用 $Super$$main 转到 main() 函数执行，
这样可以让用户不用去管 main() 之前的系统初始化操作
```

rtthread_startup()是真正的启动函数
```C
int rtthread_startup(void)
{
    rt_hw_interrupt_disable();

    /* board level initalization
     * NOTE: please initialize heap inside board initialization.
     */
    rt_hw_board_init();

    /* show RT-Thread version */
    rt_show_version();

    /* timer system initialization */
    rt_system_timer_init();

    /* scheduler system initialization */
    rt_system_scheduler_init();

#ifdef RT_USING_SIGNALS
    /* signal system initialization */
    rt_system_signal_init();
#endif

    /* create init_thread */
    rt_application_init();

    /* timer thread initialization */
    rt_system_timer_thread_init();

    /* idle thread initialization */
    rt_thread_idle_init();

    /* start scheduler */
    rt_system_scheduler_start();

    /* never reach here */
    return 0;
}
```

其中，主函数入口是在rt_application_init函数中创建的：
```C
void rt_application_init(void)
{
    rt_thread_t tid;

#ifdef RT_USING_HEAP
    tid = rt_thread_create("main", main_thread_entry, RT_NULL,
                           RT_MAIN_THREAD_STACK_SIZE, RT_MAIN_THREAD_PRIORITY, 20);
    RT_ASSERT(tid != RT_NULL);
#else
    rt_err_t result;

    tid = &main_thread;
    result = rt_thread_init(tid, "main", main_thread_entry, RT_NULL,
                            main_stack, sizeof(main_stack), RT_MAIN_THREAD_PRIORITY, 20);
    RT_ASSERT(result == RT_EOK);
	
    /* if not define RT_USING_HEAP, using to eliminate the warning */
    (void)result;
#endif

    rt_thread_startup(tid);
}
```

主函数入口
```C
void main_thread_entry(void *parameter)
{
    extern int main(void);
    extern int $Super$$main(void);

    /* RT-Thread components initialization */
    rt_components_init();

    /* invoke system main function */
#if defined (__CC_ARM)
    $Super$$main(); /* for ARMCC. */
#elif defined(__ICCARM__) || defined(__GNUC__)
    main();
#endif
}
```

## 与裸机相比

![Img](/00-嵌入式软件工程师/05-RT_Thread/02-RT_Thread官方入门教程/01-初识RT_Thread/FILES/初识RT_Thread.md/img-20230419211556.png)

![Img](/00-嵌入式软件工程师/05-RT_Thread/02-RT_Thread官方入门教程/01-初识RT_Thread/FILES/初识RT_Thread.md/img-20230419211603.png)















