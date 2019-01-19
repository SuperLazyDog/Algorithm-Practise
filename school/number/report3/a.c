#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  FILE *f = fopen("a.txt", "r");
  char str[128], div[] = ",";
  int count = 0;
  double t, x, y;
  t = x = y = 0.0;
  while(fgets(str, 128, f) != NULL) {
    if (count%2 == 0) { // t
      t = atof(strtok(str, div));
      t = (t+atof(strtok(NULL, div)))/2.0;
    } else { // x, y
      x = atof(strtok(str, div));
      x = (x+atof(strtok(NULL, div)))/2.0;
      y = (atof(strtok(NULL, div)) + atof(strtok(NULL, div)))/2.0;
      printf("%.15g %.15g %.15g\n", t, x, y);
    }
		count++;
	}
  fclose(f);
  return 0;
}
