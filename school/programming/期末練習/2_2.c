#include <stdio.h>

long unsigned func(long unsigned n);

int main() {
  int a[10000], count = 0;
  for (int i = 0; i < 9999; i++) {
    if (i == (int)func(i)) {
      a[count++] = i;
    }
  }

  for (int i = 0; i < count; i++) {
    printf("result[%d]: %d\n", i, a[i]);
  }
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
