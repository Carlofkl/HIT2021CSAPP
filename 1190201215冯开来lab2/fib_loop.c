#include <stdio.h>
int main()
{
	int a = 0, b = 1, i;
	printf("fib_loop(0) = %d\n", a);
	printf("fib_loop(1) = %d\n", b);
    for(i = 2;i <= 100;i++)
    {
        int t = b;
        b = a + b;
        a = t;
		printf("fib_loop(%d) = %d\n", i, b);
    }
	return 0;
}
