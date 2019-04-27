#include <stdio.h>

main()
{
	double a, b, c, x;

	a = 3.14159265358979;
	b = 1e10;
	c = -1e10;

	x = (a + b) + c;
	printf("%.17g\n", x);
	x = a + (b + c);
	printf("%.17g\n", x);
}
