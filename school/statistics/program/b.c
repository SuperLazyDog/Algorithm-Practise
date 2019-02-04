#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solution(char fName[]);
int compareEle(const void * a, const void * b);
int main(int argc, char const *argv[]) {
  char fName[128], quit[] = "q";
  do {
    printf("ファイル名を入力してください: ");
    scanf("%s",  fName);
    solution(fName);
  } while(strcmp(fName, quit));
  return 0;
}

void solution(char fName[]) {
  // 必要な変数のステートメント
  FILE *fp = fopen(fName, "r");
  char str[128];
  int length = 128, temp, *arys;
  long i, aryLength;
  double arg=0., sd = 0., s2, t;
  // 読み込み処理
  fgets(str, length, fp);
  sscanf(str, "length: %ld", &aryLength);
  arys = (int *)malloc(sizeof(int)*aryLength);
  while (fgets(str, length, fp) != NULL) {
    sscanf(str, "data[%ld]: %d", &i, &temp);
    arys[i] = temp;
    arg += temp;
  }
  // 計算処理
  arg /= aryLength;
  // char newFile[128]="_";
  // strcat(newFile, fName);
  // FILE *new = fopen(newFile, "w");
  qsort(arys, aryLength, sizeof(int), compareEle);
  for (int i = 0; i < aryLength; i++) {
    // printf("data[%d]: %d\n", i, arys[i]);
    sd += pow(((double)arys[i]-arg), 2);
    // fprintf(new, "%d\n", arys[i]);
  }
  // fclose(new);
  s2 = sd/(aryLength-1);
  sd = sqrt(sd/aryLength);
  // 結果を出力
  printf("平均値: %f, 中央値: %d, 最大値: %d, 最小値: %d, 区間の中央: %f\n",
    arg, arys[(aryLength-1)/2], arys[aryLength-1], arys[0],
    ((double)arys[aryLength-1] + (double)arys[0])/2.);
  printf("標準偏差: %f\n", sd);
  printf("不偏分散: %f, 不偏分散: %f\n", s2, sqrt(s2));
  t = 1.960*sqrt(s2)/sqrt(aryLength);
  printf("t: %f, arg+t: %f, arg-t: %f\n", t, arg+t, arg-t);
  t = (arg-1000000000)/sqrt(s2);
  printf("t: %f\n", t);
  // 参照先を閉じる
  fclose(fp);
  free(arys);
}

int compareEle(const void * a, const void * b) {
  return *(int *)a-*(int *)b;
}
