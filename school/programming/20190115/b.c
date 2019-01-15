#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isS(int i);
int main(int argc, char const *argv[]) {
  int capacity = 8, head = -1;
  int *ary = (int *)malloc(sizeof(int)*capacity);
  int t = 1;
  while (1) {
    if (isS(t)) {
      if (head+1>=capacity) {
        capacity *= 2;
        ary = realloc(ary, capacity);
      }
      ary[++head] = t;
      for (int i = 0; i <= head; i++) {
        double result = sqrt((t-ary[i])/2);
        if (result != (int)result) {
          printf("result: %f\n", result);
          printf("%d\n", t);
          return 0;
        }
      }
    }
    t++;
  }
  return 0;
}

int isS(int n) {
  int limit = sqrt(n);
  for (int i = 2; i <= limit; i++) {
    if (n%2 == 0) {
      return 0;
    }
  }
  return 1;
}
