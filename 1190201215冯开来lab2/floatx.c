#include <stdio.h>
int main ()
{
    float a = +0.0;
    int a2 = 0;
    float b = -0.0;
    int b2 = 0x80000000;
    float c = 0x00000001;
    int c2 = 0x00000001;
    float d = 0x7f7fffff;
    int d2 = 0x7f7fffff;
    float e = 0x00800000;
    int e2 = 0x00800000;
    float f = 0x7f800000;
    int f2 = 0x7f800000;
    float g = 0x7f800001;
    int g2 = 0x7f800001;

    printf("%f\t\t\t0x%X\n", a, a2);
    printf("%f\t\t\t0x%X\n", b, b2);
    printf("%f\t\t\t0x%X\n", c, c2);
    printf("%f\t\t0x%X\n", d, d2);
    printf("%f\t\t\t0x%X\n", e, e2);
    printf("%f\t\t0x%X\n", f, f2);
    printf("%f\t\t0x%X\n", g, g2);
}
