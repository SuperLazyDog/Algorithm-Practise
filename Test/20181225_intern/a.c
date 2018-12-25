#include <stdio.h>

void solution() {
  char a[] = "\n", b[] = "!\n";
  int temp;
  for (int i = 1; i < 151; i++) {
    printf("%d", i);
    temp = i;
    int hasT = 0;
    while (temp > 0) {
      if (temp % 10 == 3) {
        hasT = 1;
      }
      temp = temp /10;
    }
    if (i % 3 == 0 || hasT) {
      printf("%s", b);
    } else {
      printf("%s", a);
    }
  }
}
int main(int argc, char const *argv[]) {
  solution();
  return 0;
}
