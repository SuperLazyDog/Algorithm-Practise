#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LIMIT 0.00000000001
typedef struct o {
  char num[4], exp[7];
  int t[4];
} NE;
void solution(NE s, int n);
double caculate(double a, double b, char type);
double expCaculate(char str[7]);
void showStandartExp(char str[7]);
int main(int argc, char const *argv[]) {
  char str[4], over[] = "quit";
  do {
    NE s;
    for (size_t i = 0; i < 4; i++) {
      s.t[i] = 0;
    }
    printf("num(abcd): ");
    scanf("%s", s.num);
    solution(s, 0);
  } while(strcmp(str, over));
  return 0;
}

void solution(NE s, int n) {
  // abOcOOdOOO
  //   O OO OOO
  //   111 abXcXdX
  //   102 abXcdXX
  //   012 abcXdXX
  //   021 abcXXdX
  //   003 abcdXXX
  if (n >= 7) {
    char strs[5][8], temp[2];
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j <= 7; j++) {
        strs[i][j] = s.exp[j];
      }
    }
    temp[0] = s.exp[4]; temp[1] = s.exp[5];
    strs[1][5] = strs[1][3];
    strs[1][3] = temp[0];
    strs[1][4] = temp[1];

    strs[2][4] = strs[2][3];
    strs[2][3] = temp[0];

    strs[3][4] = strs[3][3];
    strs[3][3] = strs[3][2];
    strs[3][2] = temp[0];

    strs[4][5] = strs[4][3];
    strs[4][3] = strs[4][2];
    strs[4][4] = temp[1];
    strs[4][2] = temp[0];

    for (size_t i = 0; i < 5; i++) {
      if (fabs(expCaculate(strs[i])-10.)<LIMIT) {
        showStandartExp(strs[i]);
      }
    }
  } else if (n >= 4) {
    char op[4] = {'+', '-', '*', '/'};
    for (size_t i = 0; i < 4; i++) {
      s.exp[n] = op[i];
      solution(s, n+1);
    }
  } else {
    for (int i = 0; i < 4; i++) {
      if (!s.t[i]) {
        s.t[i] = 1;
        s.exp[n] = s.num[i];
        solution(s, n+1);
        s.t[i] = 0;
      }
    }
  }
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
  double numS[4];
  int numCount, i, temp;
  numCount = i = 0;
  while (str[i]) {
    temp = str[i]-'0';
    if (temp >= 0 && temp < 10) {
      numS[numCount++] = temp;
    } else {
      double b = numS[--numCount], a = numS[--numCount];
      numS[numCount++] = caculate(a, b, str[i]);
    }
    i++;
  }
  return numS[--numCount];
}

void showStandartExp(char str[7]) {
  char strS[4][32];
  for (int i = 0; i < 4; i++) {
    strcpy(strS[i], "");
  }
  int count, i, temp;
  count = i = 0;
  while (str[i]) {
    temp = str[i]-'0';
    if (temp >= 0 && temp < 10) {
      char ctemp[32];
      sprintf(ctemp, "%c", str[i]);
      strcpy(strS[count++], ctemp);
    } else {
      char b[16], a[16], temp[32];
      strcpy(b, strS[--count]);
      strcpy(a, strS[--count]);
      if (i == 6) {
        sprintf(temp, "%s%c%s", a, str[i], b);
      } else {
        sprintf(temp, "(%s%c%s)", a, str[i], b);
      }
      strcpy(strS[count++], temp);
    }
    i++;
  }
  printf("%s\n", strS[0]);
}
