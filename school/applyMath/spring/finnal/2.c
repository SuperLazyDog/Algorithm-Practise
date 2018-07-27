#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>

int main(int argc, char const *argv[]) {
  double a = 1., b = pow(10., 15.), c = pow(10., 14.);
  double tri = b*b - 4.*a*c, sqrtTri = sqrt(tri);
  double fst, sed;
  fst = (-b+sqrtTri)/(2.*a);
  sed = -((2.*c)/(b+sqrtTri));
  printf("a: %f, b: %f, c: %f\n", a, b, c);
  printf("tri: %f, sqrtTri: %f, tmp: %f, %f\n", tri, sqrtTri, sqrtTri*sqrtTri, pow(tri, 0.5));
  printf("b+sqrtTri: %f, -b+sqrtTri: %f\n", b+sqrtTri, -b+sqrtTri);
  printf("fst = %f, sed = %f\n", fst, sed);
  return 0;
}
