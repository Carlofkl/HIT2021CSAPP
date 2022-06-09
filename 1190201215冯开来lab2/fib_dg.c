#include <stdio.h>
int fib_dg(int x)
{
    if(x <= 0)
    {
        return 0;
    }
	if(x == 1)
	{
		return 1;
	}
	return fib_dg(x - 1) + fib_dg(x - 2);
}
int main()
{
	int i;
	for(i = 0; i <= 100; ++i)
    {
		printf("fib_dg(%d) = %d\n", i, fib_dg(i));
	}
	return 0;
}
