#include <stdio.h>

int main() {
  double result = 0;
  int sign = 1;
  for (int i = 1; i <= 9999; i += 2) {
    result +=  sign * (double)4/i;
    sign *= -1;
  }
  printf("result: %f\n", result);
  return 0;
}
