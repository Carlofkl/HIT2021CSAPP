#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void showbyte(byte_pointer start, size_t len)
{
    size_t i;
    for (i=0; i<len; i++)
        printf(" %.2x",start[i]);
    printf("\n");
}
int main()
{
    char str[7] = "冯开来";
    showbyte((byte_pointer)str, sizeof(str));
    printf("hello, 1190201215冯开来\n");
}
