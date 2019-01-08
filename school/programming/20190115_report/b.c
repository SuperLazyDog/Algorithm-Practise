#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct r {
  double a[4];
  int b[4];
  int temp[7];
};
double o(double a, double b, int mode);
void showTemp(struct r temp) {
  char oo[4] = { '+', '-', '*', '/'};
  char ooo[2] = {'(', ')'};
  double result1;
  result1 = o(temp.temp[0], temp.temp[2], temp.temp[1]);
  result1 = o(result1, temp.temp[4], temp.temp[3]);
  result1 = o(result1, temp.temp[6], temp.temp[5]);
  for (size_t i = 0; i < 7; i++) {
    printf("%d ", temp.temp[i]);
  }
  puts("");
  printf("result1: %f\n", result1);
  for (int i = 0; i < 7; i++) {
    // printf("%d", temp[i]);
    if (i%2 == 0) {
      int type = temp.temp[i] > 0 ? 0:1;
      int count = temp.temp[i]/10000;
      for (int i = 0; i < count; i++) {
        printf("%c", ooo[type]);
      }
      printf("%c", (temp.temp[i]%10+10)%10+'0');
    } else {
      printf("%c", oo[temp.temp[i]-1]);
    }
  }
  puts("");puts("");
}

void swapTo(int k, int array[]) {
  int temp = array[k];
  for (int i = k; i > 0; i--) {
    array[i] = array[i-1];
  }
  array[0] = temp;
}

void solution(struct r temp, double result, int n) {
  if (n >= 4) {
    double s = pow(10, -5);
    char oo[4] = { '+', '-', '*', '/'};
    if (fabs(result-10.0) < s) {
      printf("result: %f\n", result);
      showTemp(temp);
    }
    return;
  }
  if (n == 0) {
    for (int i = 0; i < 4; i++) {
      if (!temp.b[i]) {
        temp.b[i] = 1;
        temp.temp[0] = temp.a[i];
        solution(temp, temp.a[i], n+1);
        temp.b[i] = 0;
      }
    }
  } else {
    for (int i = 0; i < 4; i++) {
      if (!temp.b[i]) {
        temp.b[i] = 1;
        temp.temp[2*n] = temp.a[i];
        temp.temp[2*n-1] = 1;
        solution(temp, o(result, temp.a[i], 1), n+1);
        // TODO: 反过来怎么处理a[]
        temp.temp[2*n-1] = 2;
        solution(temp, o(result, temp.a[i], 2), n+1);
        temp.temp[2*n-1] = 3;
        solution(temp, o(result, temp.a[i], 3), n+1);
        temp.temp[2*n-1] = 4;
        solution(temp, o(result, temp.a[i], 4), n+1);



        // temp.temp[0] += 10000;
        // if (temp.temp[2*n-2] > 0) {
        //   temp.temp[2*n-2] *= -1;
        // }
        // temp.temp[2*n-2] -= 10000;
        // // for (int i = 0; i < 7; i++) {
        // //   printf("%d ", temp.temp[i]);
        // // }
        // // puts("");
        // int t0 = temp.temp[2*n], t1 = temp.temp[2*n-1];
        // for (int i = 2*n-2; i >= 0; i--) {
        //   temp.temp[i+2] = temp.temp[i];
        // }
        // temp.temp[0] = t0;
        // temp.temp[1] = t1;
        // // for (int i = 0; i < 7; i++) {
        // //   printf("%d ", temp.temp[i]);
        // // }
        // // puts("");
        temp.temp[2*n-1] = 1;
        solution(temp, o(temp.a[i], result, 1), n+1);
        temp.temp[2*n-1] = 2;
        solution(temp, o(temp.a[i], result, 2), n+1);
        temp.temp[2*n-1] = 3;
        solution(temp, o(temp.a[i], result, 3), n+1);
        temp.temp[2*n-1] = 4;
        solution(temp, o(temp.a[i], result, 4), n+1);
        temp.b[i] = 0;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  double a[4];
  char str[4];
  int b[4] = {0, 0, 0, 0};
  struct r temp;
  do {
    printf("num(abcd): ");
    scanf("%s", str);
    for (int i = 0; i < 4; i++) {
      temp.a[i] = str[i] - '0';
      temp.b[i] = 0;
      printf("a[%d]: %f\n", i, temp.a[i]);
    }
    solution(temp, 0, 0);
  } while(strcmp(str, "quit"));
  return 0;
}

double o(double a, double b, int mode) {
  switch (mode) {
    case 1:
      return a + b;
    case 2:
      return a - b;
    case 3:
      return a * b;
    default:
      return a / b;
  }
}
// }
