#include <stdio.h>
#include <stdlib.h>

struct point {
    double x;
    double y;
};

int compare (const void *arg1, const void *arg2) {
  struct point *l = (struct point *)arg1, *r = (struct point *)arg2;
  return (l->x*l->x + l->y*l->y) > (r->x*r->x + r->y*r->y);
}

int main()
{
    int i, n;
    struct point* dat;

    scanf("%d", &n);

    dat = (struct point *)malloc(sizeof(struct point) * n);

    for (i=0; i<n; i++) {
        scanf("%lf", &(dat[i].x));
        scanf("%lf", &(dat[i].y));
    }

    qsort(dat, n, sizeof(struct point), compare);

    for (i=0; i<n; i++) {
        printf("%g %g\n", dat[i].x, dat[i].y);
    }

    free(dat);

    return 0;
}
