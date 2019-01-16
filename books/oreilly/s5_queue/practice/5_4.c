// 给定数组和幅度, 生成一个包含每一块的最大值的新数组
#include <stdio.h>
#include <stdlib.h>

// O(n)
void getMaxArray(int *a, int size, int wide, int *result) {
  if (!a || !result) {
    return;
  }
  if (size-wide < 0) {
    return;
  }
  int l = size-wide+1;
  for (int i = 0; i < l; i++) {
    int limit = i + wide;
    int temp = a[i];
    for (int j = i+1; j < limit; j++) {
      if (temp < a[j]) {
        temp = a[j];
      }
    }
    result[i] = temp;
  }
}

int main(int argc, char const *argv[]) {
  int a[8] = {1, 3, -1, -3, 5, 3, 6, 7}, b[6];
  getMaxArray(a, 8, 3, b);
  for (int i = 0; i < 6; i++) {
    printf("b[%d]: %d\n", i, b[i]);
  }
  return 0;
}
