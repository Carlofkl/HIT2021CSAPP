
//A.��������ʱ����λ���ȴ������������ֽ��������������
//B.������bad_int_size_is_32()��˵ʵ���Ҿ��������ַ����о����Ǻܺã��������˲�����λΪ1��Ϊ�������ص㣬�õİ취�����˺ܾ�Ҳû�������
//C.������bad_int_size_is_16()����Ч��32λ���ġ�

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
