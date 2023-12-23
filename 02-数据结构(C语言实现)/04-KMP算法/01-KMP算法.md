---

# 注释：文件开头使用YAML语法配置文章信息，之后是正常的Markdown语法
# Note: The beginning of the file uses YAML syntax to configure the blog meta data, followed by the normal Markdown syntax.

# 此处如果不配置标题，则提取Markdown中的一级标题，或使用文件名
# Title will be extracted from heading 1 of markdown or using file name if not configured here.
title: KMP算法

# 此处如果不配置摘要，则从正文提取开头若干文字
# Abstract will be extracted from the begining of markdown content if not configured here.
abstract: 本节将主要描述了KMP算法的原理及kmp算法的使用

# URL用于固定链接、编辑文章功能，建议所有文章都配置
# URL is used for permalink and article editing, and it is recommended to be configured.
url: KMP-01


# 文章发布时间，使用的时区和系统设置一致，不设置则使用当前时间
# Article post time, time zone is the same as the system settings. Current time will be used if not configured here.
date: 2023-07-25 20:00:05


# 文章分类
category:
- 数据结构与算法


# 文章标签
tags:
- C
- 数据结构与算法
- KMP

---


# 01-KMP算法


# 什么是KMP
因为是由这三位学者发明的：Knuth，Morris和Pratt，所以取了三位学者名字的首字母。所以叫做KMP

# KMP的作用

KMP主要应用在字符串匹配上。

MP的主要思想是当出现字符串不匹配时，可以知道一部分之前已经匹配的文本内容，可以利用这些信息避免从头再去做匹配了。

# 前缀表
前缀表：记录下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀

前缀表是用来回退的，它记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配。

前缀表的任务是当前位置匹配失败，找到之前已经匹配上的位置，再重新匹配，此也意味着在某个字符失配时，前缀表会告诉你下一步匹配中，模式串应该跳到哪个位置。

# 最长公共前后缀

前缀：不包含最后一个字符的所有以第一个字符开头的连续子串。

后缀：不包含第一个字符的所有以最后一个字符结尾的连续子串。

用“最长相等前后缀” 更准确一些。

因为前缀表要求的就是相同前后缀的长度。

字符串a的最长相等前后缀为0。 字符串aa的最长相等前后缀为1。 字符串aaa的最长相等前后缀为2。


# 前缀表计算
```C
int* GetNext(char* s)
{
    assert(s);
    int j = -1;
    int len = strlen(s);
    int* next = (int*)malloc(len * sizeof(int));
    next[0] = j;
    for(int i = 1; i < len; i++)
    {   
        while(j >= 0 && s[i] != s[j + 1])
        {
            j = next[j];
        }

        if(s[i] == s[j + 1])
        {
            j++;
        }
        next[i] = j;
    }
    return next;
}
```

# 28.实现strstr
```C
int strStr(char * haystack, char * needle){
    assert(haystack);
    assert(needle);

    int* next = GetNext(needle);

    int haylen = strlen(haystack);
    int neelen = strlen(needle);
    int j = -1;
    for(int i = 0; i < haylen; i++)
    {

        while(j >= 0 && haystack[i] != needle[j + 1])
        {
            j = next[j];
        }
        if(haystack[i] == needle[j + 1])
        {
            j++;
        }
        if(neelen == j + 1)
        {
            return i - neelen + 1;
        }
    }
    return -1;
}
```






