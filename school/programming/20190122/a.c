#include <stdio.h>

void solution(void);
int main(int argc, char const *argv[]) {
  solution();
  return 0;
}

void solution(void) {
  double sum = 0.0, i = 1.0;
  while (sum < 10) {
    sum += 1/i;
    i++;
  }
  printf("%.30f\n", sum);
}
