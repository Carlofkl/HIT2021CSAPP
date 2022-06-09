#include<stdio.h>
#include<string.h>
float atoi1(char *str)
{
    //printf("%d\n", *str);
    float b = 0;
    while (*str != '.')
    {
        float a = *str - '0';
        //printf("%d\n", a);
        str ++;
        b = 10 * b + a;
    }
    //printf("%f\n",b);
    return b;
}
float atoi2(char *str)
{
    float b = 0;
    while (*str != '\0')
        str++;
    str--;
    while(*str != '.')
    {
        float a = *str - '0';
        b = b/10 + a;
        str --;
    }
    return b/10;
}
int main()
{
    float num1;
    float num2;
    float num;
    char str[100] = "";
    scanf("%s", str);
    char *ptr = str;
    if (*ptr == '-')
    {
        ptr ++;
        num1 = -atoi1(ptr);
        num2 = -atoi2(ptr);
    }
    else
    {
        num1 = atoi1(str);
        num2 = atoi2(str);
    }
    num = num1 + num2;
    printf("%f\n",num);
}
