#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, x;

	a = 1.;
	b = 1e15;
	c = 1e14;

	x = (-b + sqrt(b * b - 4. * a * c)) / (2. * a);

	printf("%.17g\n", x);
}
