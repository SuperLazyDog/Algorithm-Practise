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

int main(int argc, char const *argv[]) {

  interval a, b, c, tmp_4, tmp_2,tmp_minus_1, fst, sed;
  a.inf = a.sup = 1.;
  b.inf = b.sup = pow(10., 15.);
  c.inf = c.sup = pow(10., 14.);
  tmp_4.inf = tmp_4.sup = 4.;
  tmp_2.inf = tmp_2.sup = 2.;
  tmp_minus_1.inf = tmp_minus_1.sup = -1.;
  interval tri = interval_sub(interval_mul(b, b), interval_mul(tmp_4, interval_mul(a, c)));
  interval sqrtTri = interval_sqrt(tri);
  fst = interval_div(interval_sub(sqrtTri, b), interval_mul(tmp_2, a));
  sed = interval_mul(tmp_minus_1, interval_div(interval_mul(tmp_2, c), interval_add(b, sqrtTri)));
  interval_print(fst);
  interval_print(sed);
  printf("tri: ");
  interval_print(tri);
  printf("sqrtTri^2: ");
  interval_print(interval_mul(sqrtTri, sqrtTri));
  return 0;
}
