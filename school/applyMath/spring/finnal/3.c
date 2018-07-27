#include <stdio.h>
#define LIMIT 18
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
  double sum = 0;
  while (sum<n) {
    sum += 1./i;
    i++;
  }
  return (long unsigned)i;
}
