#include<stdio.h>
#include<string.h>
int atoi(char *str)
{
    //printf("%d\n", *str);
    int b = 0;
    while (*str != '\0')
    {
        int a = *str - '0';
        //printf("%d\n", a);
        str ++;
        b = 10 * b + a;
    }
    return b;
}
int main()
{
    int num;
    char str[100] = "";
    scanf("%s", str);
    char *ptr = str;
    if (*ptr == '-')
    {
        ptr ++;
        num = -atoi(ptr);
    }
    else
        num = atoi(ptr);
    printf("%d\n",num);
}

