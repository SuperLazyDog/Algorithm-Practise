#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct c {
  int t[10];
  char c[10];
} Num;

void buildNum(Num num, int n);

int main(int argc, char const *argv[]) {
  Num *n = (Num *)malloc(sizeof(Num));
  for (int i = 0; i < 10; i++) {
    n->t[i] = 0;
    sprintf(&n->c[i], "%d", 0);
  }
  buildNum(*n, 1);
  free(n);
  return 0;
}

void buildNum(Num num, int n) {
  if (n>=10) {
    long n;
    double sqrtN;
    sscanf(num.c, "%ld", &n);
    sqrtN = sqrt(n);
    if (sqrtN == (int)sqrtN) {
      printf("%ld\n", n);
    }
    return;
  }
  for (int i = 1; i < 10; i++) {
    if (num.t[i] == 0) {
      num.t[i] = 1;
      num.c[n] = (char)i;
      sprintf(&num.c[n], "%d", i);
      buildNum(num, n+1);
      num.t[i] = 0;
    }
  }
}
