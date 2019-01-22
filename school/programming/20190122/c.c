#include <stdio.h>

void solution(int n);

int main(int argc, char const *argv[]) {
  for (int i = 1; i < 21; i++) {
    solution(i);
  }
  return 0;
}
void subSolution(int i, int t, int top, int *count) {
  if (i == top) {
    (*count)++;
    return;
  }
  if (i > top) {
    return;
  }
  for (int j = 1; j <= t; j++) {
    subSolution(j+i, j, top, count);
  }
}

void solution(int n) {
  int count = 0;
  subSolution(0, n, n, &count);
  printf("n=%d: %d\n", n, count);
}
