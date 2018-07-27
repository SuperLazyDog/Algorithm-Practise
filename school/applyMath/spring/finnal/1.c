#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>

typedef struct {
    double inf;
    double sup;
} interval;

interval interval_add(interval x, interval y)
{
    interval z;

    fesetround(FE_DOWNWARD);
    z.inf = x.inf + y.inf;

    fesetround(FE_UPWARD);
    z.sup = x.sup + y.sup;

    fesetround(FE_TONEAREST);

    return z;
}

interval interval_sub(interval x, interval y)
{
  interval z;

  fesetround(FE_DOWNWARD);
  z.inf = x.inf - y.sup;

  fesetround(FE_UPWARD);
  z.sup = x.sup - y.inf;

  fesetround(FE_TONEAREST);

  return z;
}

interval interval_mul(interval x, interval y)
{
  interval z;
  double tmp;

  if (x.inf >= 0.) {
  	if (y.inf >= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.inf * y.inf;
  		fesetround(FE_UPWARD);
  		z.sup = x.sup * y.sup;
  	} else if (y.sup <= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.sup * y.inf;
  		fesetround(FE_UPWARD);
  		z.sup = x.inf * y.sup;
  	} else {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.sup * y.inf;
  		fesetround(FE_UPWARD);
  		z.sup = x.sup * y.sup;
  	}
  } else if (x.sup <= 0.) {
  	if (y.inf >= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.inf * y.sup;
  		fesetround(FE_UPWARD);
  		z.sup = x.sup * y.inf;
  	} else if (y.sup <= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.sup * y.sup;
  		fesetround(FE_UPWARD);
  		z.sup = x.inf * y.inf;
  	} else {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.inf * y.sup;
  		fesetround(FE_UPWARD);
  		z.sup = x.inf * y.inf;
  	}
  } else {
  	if (y.inf >= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.inf * y.sup;
  		fesetround(FE_UPWARD);
  		z.sup = x.sup * y.sup;
  	} else if (y.sup <= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.sup * y.inf;
  		fesetround(FE_UPWARD);
  		z.sup = x.inf * y.inf;
  	} else {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.inf * y.sup;
  		tmp = x.sup * y.inf;
  		if (tmp < z.inf) z.inf = tmp;
  		fesetround(FE_UPWARD);
  		z.sup = x.inf * y.inf;
  		tmp = x.sup * y.sup;
  		if (tmp > z.sup) z.sup = tmp;
  	}
  }
  fesetround(FE_TONEAREST);

  return z;
}

interval interval_div(interval x, interval y)
{
  interval z;
  if (y.inf <= 0 && y.sup >= 0) {
    printf("zero divide!\n");
    exit(1);
  }
  if (y.inf > 0.) {
  	if (x.inf >= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.inf / y.sup;
  		fesetround(FE_UPWARD);
  		z.sup = x.sup /  y.inf;
  	} else if (x.sup <= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.inf / y.inf;
  		fesetround(FE_UPWARD);
  		z.sup = x.sup / y.sup;
  	} else {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.inf / y.inf;
  		fesetround(FE_UPWARD);
  		z.sup = x.sup / y.inf;
  	}
  } else if (y.sup < 0.) {
  	if (x.inf >= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.sup / y.sup;
  		fesetround(FE_UPWARD);
  		z.sup = x.inf / y.inf;
  	} else if (x.sup <= 0.) {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.sup / y.inf;
  		fesetround(FE_UPWARD);
  		z.sup = x.inf / y.sup;
  	} else {
  		fesetround(FE_DOWNWARD);
  		z.inf = x.sup / y.sup;
  		fesetround(FE_UPWARD);
  		z.sup = x.inf / y.sup;
  	}
  }
  fesetround(FE_TONEAREST);

  return z;
}

interval interval_sqrt(interval x)
{
  interval z;
  if (x.inf < 0.) {
    printf("minus sqrted!\n");
    exit(1);
	}

	fesetround(FE_DOWNWARD);
	z.inf = sqrt(x.inf);
	fesetround(FE_UPWARD);
	z.sup = sqrt(x.sup);
	fesetround(FE_TONEAREST);

  return z;
}

void interval_print(interval x)
{
    printf("[%.17g,%.17g]\n", x.inf, x.sup);
}

int main()
{
  interval x, y, z;

  x.inf = 1; x.sup = 2;
  y.inf = 3; y.sup = 4;

  z = interval_add(x, y);

  interval_print(z);

  z = interval_sub(x, y);

  interval_print(z);

  z = interval_mul(x, y);

  interval_print(z);

  z = interval_div(x, y);

  interval_print(z);

  z = interval_sqrt(x);

  interval_print(z);

  return 0;
}
