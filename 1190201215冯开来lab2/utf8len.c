#include<stdio.h>
int GetUtf8Len(char* str)
{
    char *s = str;
    int length = 0;
    char num;
    while (*s != '\0')
    {
        length ++;
        num = *s;
        if((num & 0x80)==0)
            s++;
        else
        {
            int result = 0;
            do{
                num *= 2;
                result++;
            }while(num & 0x80);
            s += result;
        }
    }
    return length;
}
int main()
{
    char str[100] = "";
    scanf("%s", str);
    printf("%d\n", GetUtf8Len(str));
    return 0;
}
