#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 行列ADT
typedef struct matrix {
  int rows, columns;
  double **datas;
} Matrix;

Matrix *createMatrix(int rows, int columns);
void deleteMatrix(Matrix *m);
void showMatrix(Matrix *m);
// ガウス消去法
void gaussForward(Matrix *a, Matrix *b);
void gaussBackward(Matrix *a, Matrix *b);
void gauss(Matrix *a, Matrix *b);
// 課題関連
Matrix *readData(char *fname);
void setSolutionMatrix(Matrix *data, Matrix *l, Matrix *r);
void setMatrix(Matrix *m, double **datas, int rows, int columns);

int main(int argc, char const *argv[]) {
  Matrix *data = readData("data.txt");
  showMatrix(data);
  setSolutionMatrix(data, NULL, NULL);
  deleteMatrix(data);
  // Matrix *m = createMatrix(6, 6), *mm = createMatrix(6, 1);
  // showMatrix(m);
  // puts("");
  // showMatrix(mm);
  // puts("");puts("");
  // gaussForward(m, mm);
  // gaussBackward(m, mm);
  // showMatrix(m);
  // puts("");
  // showMatrix(mm);
  // deleteMatrix(m);
  // deleteMatrix(mm);
  return 0;
}

Matrix *createMatrix(int rows, int columns) {
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = rows; m->columns = columns;
  m->datas = (double **)malloc(sizeof(double *)*m->rows);
  for (int i = 0; i < m->rows; i++) {
    m->datas[i] = (double *)malloc(sizeof(double)*m->columns);
    for (int j = 0; j < m->columns; j++) {
      m->datas[i][j] = 1;
    }
  }
  return m;
}

void deleteMatrix(Matrix *m) {
  if (m) {
    if (m->datas) {
      for (int i = 0; i < m->rows; i++) {
        if (m->datas[i]) {
          free(m->datas[i]);
        }
      }
      free(m->datas);
    }
    free(m);
  }
}

void showMatrix(Matrix *m) {
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      printf("%8.6f\t", m->datas[i][j]);
    }
    puts("");
  }
}

void gaussForward(Matrix *a, Matrix *b) {
  if (!(a->rows == a->columns && b->columns == 1 && a->columns == b->rows)) {
    // 拡大係数行列でないと処理しない
    return;
  }
  int size = a->rows;
  for (int i = 0; i < size; i++) {
    // ピボット選択
    // この行と下の行のうち、該当する変数の係数が一番大きい行と交換
    int max = fabs(a->datas[i][i]), isNeedChange = 0, rowID;
    for(int j = i+1; j < size; j++) {
      int temp = fabs(a->datas[j][i]);
      if (max < temp) {
        max = temp;
        isNeedChange = 1;
        rowID = j;
      }
    }
    if (isNeedChange) {
      for (int j = 0; j < size; j++) {
        int temp = a->datas[i][j];
        a->datas[i][j] = a->datas[rowID][j];
        a->datas[rowID][j] = temp;
      }
      int temp = b->datas[i][0];
      b->datas[i][0] = b->datas[rowID][0];
      b->datas[rowID][0] = temp;
    }
    // 該当する係数によって割る
    double r = a->datas[i][i];
    for (int j = 0; j < size; j++) {
      a->datas[i][j] /= r;
    }
    b->datas[i][0] /= r;
    // 下の行から該当する変数を消去
    for(int j = i+1; j < size; j++) {
      double rr = a->datas[j][i];
      for (int k = 0; k < size; k++) {
        a->datas[j][k] -= rr*a->datas[i][k];
      }
      b->datas[j][0] -= rr*b->datas[i][0];
    }
  }
}

void gaussBackward(Matrix *a, Matrix *b) {
  if (!(a->rows == a->columns && b->columns == 1 && a->columns == b->rows)) {
    // 拡大係数行列でないと処理しない
    return;
  }
  for (int i = b->rows-1; i >= 0; i--) {
    for(int j = i+1; j < b->rows; j++) {
      b->datas[i][0] -= a->datas[i][j]*b->datas[j][0];
      a->datas[i][j] = 0;
    }
  }
}

void guass(Matrix *a, Matrix *b) {
  gaussForward(a, b);
  gaussBackward(a, b);
}

Matrix *readData(char *fname) {
  FILE *fp = fopen(fname, "r");
  Matrix *m;
  int temp, temp2=0;
  int bi[2];
  char str[128];
  if(fp == NULL) {
    return NULL;
	}
  for(int i = 0; i < 2; i++) {
    fgets(str, 128, fp);
    sscanf(str, "%d", &bi[i]);
  }
  m = createMatrix(bi[0], bi[1]);
  while (fgets(str, 128, fp)) {
    temp = 0;
    for (int i = 0; str[i]; i++) {
      if (str[i] != ' ') {
        m->datas[temp2][temp] = atoi(&str[i]);
        temp++;
      }
    }
    temp2++;
  }
	fclose(fp);
  return m;
}

void setMatrix(Matrix *m, double **datas, int rows, int columns) {
  if (!(rows == m->rows && columns == m->columns)) {
    return;
  }
  for(int i = 0; i < m->rows; i++) {
    for(int j = 0; j < m->columns; j++) {
      m->datas[i][j] = datas[i][j];
    }
  }
}

void setSolutionMatrix(Matrix *datas, Matrix *l, Matrix *r) {
  int dataSize = 0;
  printf("rows: %d, columns: %d\n", datas->rows, datas->columns);
  // for (int i = 0; i < datas->rows; i++) {
  //   for (int j = 0; i < datas->columns; j++) {
  //     printf("%f ", datas->datas[i][j]);
  //     if (datas->datas[i][j]) {
  //       dataSize++;
  //     }
  //   }
  //   puts("");
  // }
  printf("dataSize: %d\n", dataSize);
}
