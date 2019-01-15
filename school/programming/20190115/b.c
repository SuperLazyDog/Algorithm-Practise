#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isS(int i);
int main(int argc, char const *argv[]) {
  int capacity = 1, head = -1;
  int *ary = (int *)malloc(sizeof(int)*capacity);
  int t = 1;
  while (1) {
    if (!isS(t)) {
      if (t % 2 != 0) {
        int isMeetsNeeds = 0;
        for (int i = 0; i <= head; i++) {
          double result = sqrt((t-ary[i])/2.);
          if (result == (int)result) {
            isMeetsNeeds = 1;
            break;
          }
        }
        if (!isMeetsNeeds) {
          printf("%d\n", t);
          for (int i = head; i >= 0; i--) {
            printf("stack[%d]: %d\n", i, ary[i]);
          }
          break;
        }
      }
    } else {
      if (head+1>=capacity) {
        int size = capacity;
        capacity *= 2;
        int *temp = (int *)malloc(sizeof(int)*capacity);
        for (int i = 0; i < capacity; i++) {
          temp[i] = ary[i];
        }
        free(ary);
        ary = temp;
      }
      ary[++head] = t;
    }
    t++;
  }
  free(ary);
  return 0;
}

int isS(int n) {
  int limit = sqrt(n);
  if (n == 1 || n == 2) {
    return 1;
  }
  if (n%2 == 0) {
    return 0;
  }
  for (int i = 2; i <= limit; i++) {
    if (n%i == 0) {
      return 0;
    }
  }
  return 1;
}
