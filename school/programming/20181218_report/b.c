#include <stdio.h>
#include <stdlib.h>

void test(double (*a)[10]) {
  printf("%f\n", a[0][0]);
}

int main(int argc, char const *argv[]) {
  double a[][10] = {
    {1, 2, 3},
    {4, 5, 6}
  };
  test(a);
  return 0;
}
