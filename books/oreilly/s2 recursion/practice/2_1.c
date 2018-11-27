// 汉诺塔
// 0 1 2三根柱
// n 个圆盘
#include <stdio.h>

void hanoi(int n, int start, int temp, int des) {
  printf("n: %d\n", n);
  if (n == 1) {
    printf("n[%d]: %d -> %d\n", n, start, des);
    return;
  }
  hanoi(n-1, start, des, temp);
  printf("n[%d]: %d -> %d\n", n, start, des);
  hanoi(n-1, temp, start, des);
}

int main(int argc, char const *argv[]) {
  hanoi(64, 0, 1, 2);
  return 0;
}
