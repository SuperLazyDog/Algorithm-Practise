#include <stdio.h>

int main() {
  int n, i, j, k, count=0;

  scanf("%d", &n);
  for (i = 1; i <= 6; i++) {
    for(j = 1; j <= 6; j++) {
      for(k=1; k<=6; k++) {
        if (i+j+k == n) {
          count++;
        }
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
