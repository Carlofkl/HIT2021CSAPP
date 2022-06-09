#include<stdio.h>
int main()
{
    int num;
    int i=0;
    char str[100] = "";
    char *ptr = str;
    scanf("%d", &num);
    if (num < 0)
    {
        str[i++] = '-';
        num = -num;
    }
    if (num == 0)
        str[i++] = '0';
    else
    {
        int x=1;
        while(num/x)
        {
            x *= 10;
        }
        x /= 10;
        //printf("%d\n",x);
        while(x)
        {
            str[i++] = num/x + '0';
            num -= (num/x) * x;
            x /= 10;
            //printf("%c\n", str[i-1]);
            //printf("%s\n", ptr);
            //printf("%d %d\n", num, x);
        }
    }
    str[i] = '\0';
    printf("%s\n", ptr);

}
