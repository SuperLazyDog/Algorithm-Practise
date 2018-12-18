#include <stdio.h>
#include <stdlib.h>

void test(double **a) {
  printf("%f\n", a[0][0]);
}

int main(int argc, char const *argv[]) {
  double a[10][10] = {{1, 2}, {3, 4}};
  test(a);
  return 0;
}
