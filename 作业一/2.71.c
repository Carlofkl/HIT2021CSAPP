��һ��unsigned���͵�word�������ֽ���ɣ�32λ��
Ҫ��д������ȡ��ָ����ĳ���ֽ�
����wordΪ0x12345678��bytenumΪ0ʱȡ��0x78��bytenumΪ1ʱȡ��0x56

����������Ҫ��ȡ����������ת��Ϊ�з�������




#include <stdio.h>
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum)
{
    int a = word<<((3-bytenum)<<3);
    return y>>24;
}

