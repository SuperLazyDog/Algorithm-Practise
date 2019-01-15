#include <stdio.h>
#include <stdlib.h>

void solution(int *t, int n, int *r);

int main(int argc, char const *argv[]) {
  int t[10], r[11];
  for (size_t i = 0; i < 10; i++) {
    r[i] = 0;
  }
  solution(t, 0, r);
  for (int i = 0; i < 11; i++) {
    printf("%d: %d\n", i, r[i]);
  }
  return 0;
}

void solution(int *t, int n, int *r) {
  if (n >= 10) {
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (t[i]) {
        b++;
      } else {
        if (a < b) {
          a = b;
        }
        b = 0;
      }
    }
    printf("a: %d      ", a);
    if (a < b) {
      a = b;
    }
    r[a]++;
    for (size_t i = 0; i < n; i++) {
      printf("%d", t[i]);
    }
    printf("   a: %d\n", a);
    puts("");
    return;
  }
  t[n] = 0;
  solution(t, n+1, r);
  t[n] = 1;
  solution(t, n+1, r);
}
