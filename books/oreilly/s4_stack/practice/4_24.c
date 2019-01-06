// 求柱状图(histogram)中的最大矩形面积
#include <stdio.h>
#include <stdlib.h>
typedef struct item {
  int i, h;
} Item;

int getLargestOblong(int a[], int n) { // 4_25.c
  Item items[n], temp;
  int max = 0, current = -1, tempS;
  for (size_t i = 0; i < n; i++) {
    if (current == -1 || items[current].h < a[i]) { // 插入
      current++;
      items[current].h = a[i];
      items[current].i = i;
      continue;
    }
    while (current != -1 && items[current].h > a[i]) {
      temp = items[current];
      current--;
      tempS = temp.h * (temp.i - (current == -1 ? -1:items[current].i));
      if (tempS > max) {
        max = tempS;
      }
    }
    if (items[current].h < a[i]) {
      current++;
      items[current].h = a[i];
      items[current].i = i;
    }
  }
  while (current != -1) {
    temp = items[current];
    current--;
    tempS = temp.h * (temp.i - (current == -1 ? -1:items[current].i));
    if (tempS > max) {
      max = tempS;
    }
  }
  return max;
}
// int getLargestOblong(int a[], int n) {
//   int *b = (int *)malloc(sizeof(int)*n), result; // b[n]存储结果
//   for (size_t i = 0; i < n; i++) {
//     int c = 0;
//     b[i] = a[i];
//     for (size_t j = i; j >= 0; j--) { // 向左探索(包含自身)
//       if (b[i] <= a[j]) {
//         c++;
//       } else {
//         break;
//       }
//     }
//     for (size_t j = i+1; j < n; j++) { // 向右探索
//       if (b[i] <= a[j]) {
//         c++;
//       } else {
//         break;
//       }
//     }
//     b[i] *= c;
//   }
//   result = b[0];
//   for (size_t i = 1; i < n; i++) {
//     if (result < b[i]) {
//       result = b[i];
//     }
//   }
//   free(b);
//   return result;
// }

int main(int argc, char const *argv[]) {
  int b;
  // int c[] = {2,1,5,6,2,3};
  // int c[] = {2,1,4,5,1,3,3};
  int c[] = {5, 4, 3, 2, 1};
  // int c[] = {1, 2, 3};
  // |
  // ||
  // |||
  // ||||
  // |||||
  printf("result: %d\n", getLargestOblong(c, sizeof(c)/sizeof(int)));
  return 0;
}
