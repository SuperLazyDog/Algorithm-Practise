#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void getRandomNums(long n, char fName[]);
int main(int argc, char const *argv[]) {
  long n;
  char fName[128];
  do {
    printf("ファイル名と件数(万件)を入力してください：");
    scanf("%s %ld", fName, &n);
    getRandomNums(n, fName);
  } while(n > 0);
  return 0;
}

void getRandomNums(long n, char fName[]) {
  long l = n*10000;
  if (!strcmp(fName, "")) {
    strcpy(fName, "data.txt");
  }
  FILE *outFile = fopen(fName, "w");
  srand(time(NULL));
  fprintf(outFile, "length: %ld\n", l);
  for (long i = 0; i < l; i++) {
    fprintf(outFile, "data[%ld]: %d\n", i, rand());
  }
  fclose(outFile);
}
