#include <stdio.h>
#include <math.h>

void getResult(int n, double a, double b);

int main(int argc, char const *argv[]) {
  int n;
  double a, b;
  printf("please put you a, b, n with space\n");
  scanf("%lf %lf %d", &a, &b, &n);
  getResult(n, a, b);
  return 0;
}

void getResult(int n, double a, double b) {
  double an, bn;
  if (n<=0) {
    printf("a: %f b: %f\n", a, b);
    return NULL;
  } else {
    an = (a + b) / 2;
    bn = sqrt(a*b);
    return getResult(n-1, an, bn);
  }
}
