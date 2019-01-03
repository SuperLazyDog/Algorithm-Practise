// 生成span, 具体见书 p106
#include <stdio.h>
#include <stdlib.h>

int *getSpans(int a[], int n) {
  int *result = (int *)malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++) {
    int t = a[i];
    result[i] = 0;
    for (int j = 0; j <= i; j++) {
      if (a[j] <= a[i]) {
        result[i]++;
      } else {
        result[i] = 0;
      }
    }
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int a[5] = {6, 3, 4, 5, 2}, *b;
  b = getSpans(a, 5);
  for (int i = 0; i < 5; i++) {
    printf("b[%d]: %d\n", i, b[i]);
  }
  return 0;
}
