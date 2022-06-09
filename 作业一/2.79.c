#include<stdio.h>
#include<limits.h>
int mul3div4(int x)
{
    x = (x<<1) + x;
    if (x<0)
        return (x+(1<<2)-1)>>2;
    else
        return x>>2;
}

int main()
{
    for (int n = -10; n <=10 ; n++)
    {
        //if (Mul3div4(n) != mul3div4(n))
            printf("%d\n", 3 *n /4);
    }
    printf("end");
}

