// 生成长度n的比特列
#include <stdio.h>

#define LENGTH 12
char t[LENGTH+1];

void b(n) {
  if (n < 1) {
    printf("%s\n", t);
    return;
  }
  t[n-1] = '0';
  b(n-1);
  t[n-1] = '1';
  b(n-1);
}

int main(int argc, char const *argv[]) {
  b(LENGTH);
  return 0;
}
