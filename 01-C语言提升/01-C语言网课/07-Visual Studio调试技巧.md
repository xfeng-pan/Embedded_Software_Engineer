---

# 注释：文件开头使用YAML语法配置文章信息，之后是正常的Markdown语法
# Note: The beginning of the file uses YAML syntax to configure the blog meta data, followed by the normal Markdown syntax.

# 此处如果不配置标题，则提取Markdown中的一级标题，或使用文件名
# Title will be extracted from heading 1 of markdown or using file name if not configured here.
title:  07-Visual Studio调试技巧


# 此处如果不配置摘要，则从正文提取开头若干文字
# Abstract will be extracted from the begining of markdown content if not configured here.
abstract: 本节简要讲解了如何使用Visual Studio对编写的代码进行调试的技巧，介绍了什么是bug，什么是调试，调试的重要性，以及debug和release版本的区别，对windows调试环境进行了介绍，以及介绍了如何写出易于调试的代码。


# URL用于固定链接、编辑文章功能，建议所有文章都配置
# URL is used for permalink and article editing, and it is recommended to be configured.
url: C-07


# 文章发布时间，使用的时区和系统设置一致，不设置则使用当前时间
# Article post time, time zone is the same as the system settings. Current time will be used if not configured here.
date: 2023-07-04 20:00:07


# 文章分类
category:
- C


# 文章标签
tags:
- C
- 调试

---


# 07-Visual Studio调试技巧

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221229235254.png)


# bug是什么？

历史上第一个bug：

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221229235442.png)

第一台计算机特别大，突然有一天计算机不工作了，然后工作人员钻进计算机，在某个晶体管上面发现了这只飞蛾，清除了这个飞蛾之后，计算机恢复了正常工作。

# 调试是什么？

调试（debug，debugging），又叫做除错，是发现和减少计算机程序或电子仪器设备中程序错误的一个过程。

## 调试的基本步骤

1. 发现程序错误的存在
2. 以隔离，消除等方式对错误进行定位
3. 确定错误产生的原因
4. 提出纠正错误的解决方法
5. 对程序错误予以纠正，重新测试

# Debug和Release的介绍

## debug
debug通常被称为调试版本，包含调试信息，并且不作任何优化，方便陈煦园调试

## Release
Release版本被称为发布版本，往往进行了各种优化，是的程序在代码大小和运行速度上面都是最优的，方便用户更好的使用代码。

## 二者区别

一个c语言成语最终会在电脑中生成一个可执行文件（.exe）

Debug版本的可执行程序包含程序的调试信息
Release版本的可执行程序是被优化过的

二者相比，Debug版本的exe程序所占的空间更大

例如：以下一个程序：
```C
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		printf("%d\n", i);
	}
	system("pause");

	return 0;
}
```
该程序的功能是输出0~19的数字

程序编写完成后可以在VS的工具栏选择是使用debug版本的还是release版本的调试器

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230142058.png)

分别运行过一次程序之后，vs会在该项目的路径下生成以下两个文件：

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230142206.png)

里面会存有两个版本的可执行文件：

通过比较，会发现debug版本的文件要比release版本的文件大很多

这是debug版本：
![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230143358.png)

这是release版本：

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230143416.png)


原因是debug版本存储了调试信息，可以对程序进行调试，而release版本的则是经过优化的版本，不会存储调试信息。

在release环境下进行调试时，程序会直接运行到结束。

debug和release环境下，程序的运行是有区别的
比如：

```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
        printf("%d ", i);
		printf("hello world!\n");
		arr[i] = 0;
	}
	system("pause");
}
```
这一段代码在x86 32位系统中的debug版本中会出现死循环，而release中则不会，

死循环的原因是堆栈是arr\[12\]的地址就是i的地址

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230155809.png)
死循环时的值和内存布局有关 
![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230160000.png)

release优化结果：

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230160529.png)


在x64中则以debug会异常和警告，release中则是会报警告


# windows环境调试介绍


## 调试环境的准备

将环境更换为debug，而不是release

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230144639.png)

## 调试的快捷键
F5:跳到下一个断点处
CTRL+F5：直接执行程序，不需要调试
F11：一条一条语句的执行，可以进入函数内部
F10：用来处理过程，可以是一条语句，一盒函数
F9：设置和切换断点

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230150148.png)




功能介绍：

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230144833.png)

## 调试的时候查看程序当前信息

### 查看临时变量的值

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230150546.png)

使用自动窗口可以直接显示程序执行到的位置附近的变量

常用的调试窗口：
1. 自动窗口
2. 局部变量
3. 监视窗口
4. 内存窗口
5. 反汇编
6. 寄存器
7. 调用堆栈

## 条件断点

右键断点，输入条件


# 调试实例：

1. 求下列程序的 bug

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230154411.png)




# 如何写出易于调试的代码

## 优秀代码的特点
![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230160852.png)

## 代码示范：


### 模拟实现strcpy

优化前：

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strcpy(char* dest, char* src)
{
	while (*src != '\0')//判定源字符串是否结束，没结束才执行
	{
		if (*dest != '\0')//判定目标字符串是否越界，没越界才执行
		{
			*dest = *src;
			dest++;
			src++;
		}
		else
		{
			break;//如果目标字符串越界了，则跳出循环
		}
	}
	*dest = *src;//拷贝字符串结束标志位
}

int main()
{
	//strcpy
	//字符串拷贝

	char arr1[] = "####################";
	char arr2[] = "hello world";
	char arr3[] = "my_strcpy";

	strcpy(arr1, arr2);//调用库函数
	printf("%s\n", arr1);//通过调试可以看到arr1后面依旧有#号
	printf("%s\n", arr2);

	my_strcpy(arr1, arr3);//调用自定义函数

	printf("%s\n", arr1);//通过调试可以看到arr1后面依旧有#号
	printf("%s\n", arr3);

	return 0;
}
```
当对my_strcpy传入空指针的时候，程序会崩溃

my_strcpy优化后：
```C
void my_strcpy(char* dest, char* src)
{
	if (dest != NULL && src != NULL)//空指针判定，防止野指针的出现，增强程序的鲁棒性
	{
		while ((*dest) ? (*dest++ = *src++) : 0)//防越界与strcpy执行
		{
			;//业务代码已经在while语句中执行了
		}
		*dest = *src;//'\0'的拷贝
	}
}
```

以上程序不能及时报错

再对其进行优化：

加入断言（assert）:

assert为真则向下执行
assert为假则对外报错

assert需要引入头文件：assert.h

```C
#include <assert.h>

void my_strcpy(char* dest, char* src)
{
	assert(dest != NULL);//断言
	assert(src != NULL);//断言
	
	while ((*dest) ? (*dest++ = *src++) : 0)
	{
		;
	}
	*dest = *src;
}
```

此时，传入空指针，程序就会向外报错：

并且能显示错误出现的地方：

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230172640.png)

此时的代码并不防逻辑错误，因此还能继续优化：

前置知识：
const修饰的变量还是可以被指针修改：

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230185332.png)

因此还需要对指针加const修饰

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230185620.png)

最后代码优化为如下形式：

添加了返回值

限定了传入参数不能被修改：

```C
char*  my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);//断言
	assert(src != NULL);//断言
	//字符串拷贝
	while ((*dest) ? (*dest++ = *src++) : 0)
	{
		;
	}
	*dest = *src;//'\0'的拷贝
	return ret;
}

int main()
{
	//strcpy
	//字符串拷贝

	char arr1[] = "####################";
	char arr2[] = "hello world";
	char arr3[] = "my_strcpy";

	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	printf("%s\n", arr2);

	

	printf("%s\n", arr1);
	printf("%s\n", my_strcpy(arr1, arr3));

	return 0;
}
```

最终精简版
```C
char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);//断言
	assert(src != NULL);//断言
	//字符串拷贝
	while (*dest++ = *src++)
	{
		;
	}
	
	return ret;
}
```


总结：
1. 业务代码优化
2. assert验证
3. const限定
4. 返回值添加
5. 注释



### 模拟实现strlen

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230190851.png)


# 编程常见的错误

## 常见错误分类

### 编译型错误

双击查看信息，百度

属于最简单的一类错误

### 链接型错误

![Img](./FILES/07-Visual%20Studio调试技巧.md/img-20221230191241.png)

一般是未定义相应的函数或者变量，导致程序找不到相应的对象

可能是标识符不存在或者是编写错误

### 运行时错误

这种一般都是逻辑错误

需要靠调试逐步定位问题，属于最难解决的一类问题

debug

































