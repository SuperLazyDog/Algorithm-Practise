#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// abOcOOdOOO
//   1 23 456
//   111
//   103
//   012
//   021
//   003
double caculate(double a, double b, char type);
double expCaculate(char str[7]);
void showStandartExp(char str[7]);
int main(int argc, char const *argv[]) {
  char str[4], exp[7];
  int temp[10];
  // do {
    // int j  = 0;
    // printf("num: ");
    // scanf("%s", str);
    // for (int i = 0; i < 10; i++) {
    //   temp[i] = -9;
    // }
    // temp[0] = str[0]-'0';
    // temp[1] = str[1]-'0';
    // temp[3] = str[2]-'0';
    // temp[6] = str[3]-'0';
    // temp[7] = temp[8] = temp[9] = -1;
    // for (int i = 0; i < 10; i++) {
    //   if (temp[i] == -9) {
    //     continue;
    //   }
    //   exp[j++] = temp[i]+'0';
    // }
    // printf("%s\n", exp);
    // printf("result: %f\n", expCaculate("1234+++"));
    // puts("");
  // } while(strcmp(str, "quit"));
  printf("result: %f\n", expCaculate("1234+++"));
  showStandartExp("1234+++");
  return 0;
}

double caculate(double a, double b, char type) {
  switch (type) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
  }
  exit(1);
}

double expCaculate(char str[7]) {
  double numStack[4];
  int numCount, i, temp;
  numCount = i = 0;
  while (str[i]) {
    temp = str[i]-'0';
    if (temp >= 0 && temp < 10) {
      numStack[numCount++] = temp;
    } else {
      int b = numStack[--numCount], a = numStack[--numCount];
      numStack[numCount++] = caculate(a, b, str[i]);
    }
    i++;
    // for (int i = 0; i < numCount; i++) {
    //   printf("stack[%d]: %f\n", i, numStack[i]);
    // }
    // puts("");
  }
  return numStack[--numCount];
}

void showStandartExp(char str[7]) {
  char strStack[4][32];
  for (int i = 0; i < 4; i++) {
    strcpy(strStack[i], "");
  }
  int count, i, temp;
  count = i = 0;
  while (str[i]) {
    temp = str[i]-'0';
    if (temp >= 0 && temp < 10) {
      char temp[32];
      // sscanf(temp, "%c", str[i]);
      temp[0] = str[i];
      printf("temp: %s\n", temp);
      strcpy(strStack[count++], temp);
    } else {
      char b[32], a[32], temp[32];
      strcpy(b, strStack[--count]);
      strcpy(a, strStack[--count]);
      // sscanf(temp, "(%s+%s)", a, b);
      printf("a: %s, b: %s\n", a, b);
      strcpy(strStack[count++], temp);
    }
    i++;
    for (int i = 0; i < count; i++) {
      printf("%d: %s\n", i, strStack[i]);
    }
    puts("");
  }
}
