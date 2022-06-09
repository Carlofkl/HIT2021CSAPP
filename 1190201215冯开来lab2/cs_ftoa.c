#include <stdio.h>
#include <string.h>
int main() {
	double x;
	scanf("%lf", &x);
	int i = 0;
	char str[100];
	if (x < 0)
    {
		x = -x;
		str[i++] = '-';
	}
	if (x >= 0 && x < 1)
    {
		str[i++] = '0';
	}
	int y = x;
	int m = 1;
	while (y / m)
	{
		m *= 10;
	}
	m /= 10;
	x -= y;
	while (y)
    {
        str[i++] = y/m + '0' - 0;
		y -= m * (y/m);
		m /= 10;

	}
	if (x != 0) {
		str[i++] = '.';
		int length = 0;
		while (x && length <= 5) {
			x *= 10;
			length++;
			int temp = x;
			str[i++] = temp + '0' - 0;
			x -= temp;
		}
		while (length <= 5) {
			str[i++] = '0';
		}
		str[i] = '\0';
		if (x != 0)
		{
			x *= 10;
			int temp = x;
			x -= temp;
			i--;
			if (temp >= 5)
			{
				while (i >= 0)
				{
					if (str[i] == '.'){
						i--;
						continue;
					}
					if (str[i] == '9') {
						str[i] = '0';
						i--;
						continue;
					}
					str[i]++;
					break;
				}
			}
		}
	}
	else
	{
	    str[i++] = '.';
	    for (int j=0;j<6;j++)
        {
            str[i++] = '0';
        }
		str[i] = '\0';
	}
	printf("%s\n", str);
	return 0;
}

