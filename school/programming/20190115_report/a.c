#include <stdio.h>
#include <stdlib.h>


typedef struct a {
  int a[4]; // 四桁数値
  int b[4]; // フラグ
} A;

A *createA(int d);
void deleteA(A **a);
void showA(A *a);
void solution(A a, int i, char str[]);

int main(int argc, char const *argv[]) {
  int n;
  A *a = NULL;
  do {
    char str[7] = "";
    printf("input: ");
    scanf("%d", &n);
    a = createA(n);
    showA(a);
    solution(*a, 0, str);
    deleteA(&a);
  } while(n != -1);
  return 0;
}

A *createA(int d) {
  if (d < 0 || d > 9999) {
    return NULL;
  }
  A *new = (A *)malloc(sizeof(A));
  for (int i = 0; i < 4; i++) {
    new->a[i] = d % 10;
    new->b[i] = 0;
    d = d / 10;
  }
  return new;
}
void deleteA(A **a) {
  if (!a) {
    return;
  }
  if (*a) {
    free(*a);
  }
  *a = NULL;
}
void showA(A *a) {
  if (!a) {
    puts("no a");
    return;
  }
  for (int i = 0; i < 4; i++) {
    printf("a[%d]: %d\t b[%d]: %d\n", i, a->a[i], i, a->b[i]);
  }
  puts("");puts("");
}

void solution(A a, int i, char str[]) {
  if (i >= 7) {
    printf("%s\n", str);
    return;
  }
  if (!(i%2)) { // operant
    for (int j = 0; j < 4; j++) {
      if (!a.b[j]) {
        a.b[j] = 1;
        str[i] = '0' + a.a[j];
        solution(a, i+1, str);
        a.b[j] = 0;
      }
    }
  } else { // operator
    str[i] = '+';
    solution(a, i+1, str);
    str[i] = '-';
    solution(a, i+1, str);
    str[i] = '*';
    solution(a, i+1, str);
    str[i] = '/';
    solution(a, i+1, str);
  }
}
