#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= j; k++) {
        if (i*i + j*j + k*k == 2018) {
          printf("x: %d, y: %d, z: %d\n", k, j, i);
        }
      }
    }
  }
  return 0;
}
