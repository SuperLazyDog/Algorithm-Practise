// 生成长度n的列, 元素为 0~k-1
#include <stdio.h>
#define LENGTH 4
int t[LENGTH+1];

void buildArray(int n, int k) {
  if (n < 1) {
    for (int i = 0; i < LENGTH; i++) {
      printf("%d", t[i]);
    }
    puts("");
    return;
  }
  for (int i = 0; i < k; i++) {
    t[n-1] = i;
    buildArray(n-1, k);
  }
}

int main(int argc, char const *argv[]) {
  buildArray(LENGTH, 5);
  return 0;
}
