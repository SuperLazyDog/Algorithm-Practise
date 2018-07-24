#include <stdio.h>
#define LIMIT 10000

int sumofdivisor(int n);

int main(int argc, char const *argv[]) {
  for (int i = 0; i <= LIMIT; i++) {
    if (i == sumofdivisor(i)) {
      printf("%d\t", i);
    }
  }
  puts("");
  return 0;
}

int sumofdivisor(int n) {
  int sum = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }
  return sum;
}
