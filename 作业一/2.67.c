
//A.左移运算时，移位长度大于数据类型字节数导致数据溢出
//B.见函数bad_int_size_is_32()，说实话我觉得我这种方法感觉不是很好，但利用了补码首位为1则为负数的特点，好的办法我想了很久也没想出来。
//C.见函数bad_int_size_is_16()，仿效着32位做的。

#include<stdio.h>
int bad_int_size_is_16()
{
    int set_msb = 1 << 15;
    return set_msb;
}
int bad_int_size_is_32()
{
    int set_msb = 1 << 31;
    //int beyond_msb = (1 << 31)<<1;
    return set_msb ;
}
int main()
{
    int a = bad_int_size_is_32() /*bad_int_size_is_16()*/;
    if (a < 0 )
        printf("1\n");
    else
        printf("0\n");
}
