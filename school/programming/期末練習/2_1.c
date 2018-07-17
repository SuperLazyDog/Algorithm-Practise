#include <stdio.h>

long unsigned func(long unsigned n);

int main() {
  printf("func(145): %lu\n", func(145));
  return 0;
}

long unsigned func(long unsigned n) {
  long unsigned temp = n, result = 0, i;
  while (temp / 10 > 0) {
   i = temp % 10;
   result += i * i * i;
   temp /= 10;
  }
  result += temp * temp *temp;
  return result;
}
