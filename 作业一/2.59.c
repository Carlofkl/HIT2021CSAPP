#include<stdio.h>

int main()
{
    int x = 0x89ABCDEF;
    int c = x & 0xFF;
    int y = 0x76543210;
    int d = y & 0xFFFFFF00;
    int e = c + d;
    printf("0x%X\n", e);
}
