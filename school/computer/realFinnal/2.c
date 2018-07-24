#include <stdio.h>
#include <math.h>

#define LIMIT 10000
int main(int argc, char const *argv[]) {
  double di, dis, tmp;
  int rx, ry;
  rx = ry = 1;
  dis = 100000;
  for (int x = 1; x <= LIMIT; x++) {
    for (int y = 1; y <= LIMIT; y++) {
      di = (double)x/(double)y;
      tmp = fabs(M_PI - di);
      if (tmp < dis) {
        dis = tmp;
        rx = x;
        ry = y;
      }
    }
  }
  printf("x: %d, y: %d\n", rx, ry);
  return 0;
}
