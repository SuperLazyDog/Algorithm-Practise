// n! = n*(n-1)*...*1

// 总结
// 0! = 1 也是基本情况的一个
#include <stdio.h>

int fact(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return n*fact(n-1);
  }
}

int main(int argc, char const *argv[]) {
  for (int i = 0; i < 10; i++) {
    printf("f(%d) = %d\n", i, fact(i));
  }
  return 0;
}
