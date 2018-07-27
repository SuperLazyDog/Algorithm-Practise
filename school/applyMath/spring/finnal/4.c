#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>

#define LIMIT 18

typedef struct {
    double inf;
    double sup;
} interval;

interval interval_add(interval x, interval y);
long unsigned f(long unsigned n);

int main(int argc, char const *argv[]) {
  int count = 0;
  for (int i = 1; i <= LIMIT; i++) {
    if (count >= 4) {
      puts("");
      count = 1;
    } else {
      count++;
    }
    printf("f(%d) = %lu\t", i, f((long unsigned)i));
  }
  puts("");
  return 0;
}

long unsigned f(long unsigned n) {
  long unsigned i = 1;
  interval sum, tmp;

  sum.inf = sum.sup = 0.;
  while (sum.inf<n) {
    fesetround(FE_DOWNWARD);
    tmp.inf = 1./i;
    fesetround(FE_UPWARD);
    tmp.sup = 1./i;
    fesetround(FE_TONEAREST);
    sum = interval_add(sum, tmp);
    i++;
  }
  return i;
}

interval interval_add(interval x, interval y) {
    interval z;

    fesetround(FE_DOWNWARD);
    z.inf = x.inf + y.inf;

    fesetround(FE_UPWARD);
    z.sup = x.sup + y.sup;

    fesetround(FE_TONEAREST);

    return z;
}
