#include <stdio.h>
#include <math.h>

int isS(int n);
int solution(int i);
int main(int argc, char const *argv[]) {
  for (int i = 10001; i < 100000; i=i+2) {
    if (solution(i)) {
      printf("%d\n", i);
    }
  }
  return 0;
}

int isS(int n) {
  int limit = sqrt(n);
  if (n == 1 || n == 2) {
    return 1;
  }
  if (n%2 == 0) {
    return 0;
  }
  for (int i = 2; i <= limit; i++) {
    if (n%i == 0) {
      return 0;
    }
  }
  return 1;
}
int solution(int i) {
  int result = 1;
  while (i > 0) {
    if (!isS(i)) {
      result = 0;
      break;
    }
    i /= 10;
  }
  return result;
}
