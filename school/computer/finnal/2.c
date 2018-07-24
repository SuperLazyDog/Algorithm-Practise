#include <stdio.h>
#include <math.h>

int isPrime(unsigned n);
int func(int n);

int main(int argc, char const *argv[]) {
  int i=1;
  while (isPrime(func((unsigned)i))) {
    printf("i=%d, func(i) = %d\n", i, func((unsigned)i));
    i++;
  }
  printf("func(%d) = %d, isPrime = %d\n", i, func((unsigned)i), isPrime(func((unsigned)i)));
  return 0;
}

int func(int n) {
  return n*n + n + 41;
}

int isPrime(unsigned n) {
  int sqrtN = (int)sqrt(n);
  if (n < 2) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else if (n % 2 == 0) {
    return 0;
  } else {
    for (int i = 3; i <= sqrtN; i++) {
      if (n%i == 0) {
        return 0;
      }
    }
    return 1;
  }
}
