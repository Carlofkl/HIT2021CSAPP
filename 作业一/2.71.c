有一个unsigned类型的word，由四字节组成（32位）
要求写出函数取出指定的某个字节
比如word为0x12345678，bytenum为0时取出0x78，bytenum为1时取出0x56

代码错在哪里：要将取出来的数字转换为有符号数。




#include <stdio.h>
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum)
{
    int a = word<<((3-bytenum)<<3);
    return y>>24;
}

