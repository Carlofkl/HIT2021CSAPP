#include<stdio.h>

int isLittleEndian()
{
    int x = 0x1234567;
    char b;
    b = ((char *)&x);
    if (b == 0x12)
        return 1;
    else
        return 0;

}
int main()
{
    if (isLittleEndian())
        printf("Big Endian\n");
    else
        printf("Little Endian\n");
    return 0;
}
