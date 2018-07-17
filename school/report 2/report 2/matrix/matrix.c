#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **alloc_matrix(int n, int m)
{
	double **a;
	int i;

	a = (double **)malloc(sizeof(double *) * n);
	a[0] = (double *)malloc(sizeof(double) * n * m);
	for (i=1; i<n; i++) {
		a[i] = a[0] + i * m;
	}

	return a;
}

double *alloc_vector(int n)
{
	double *a;
	int i;

	a = (double *)malloc(sizeof(double) * n);

	return a;
}

void free_matrix(double **a)
{
	free(a[0]);
	free(a);
}

void free_vector(double *a)
{
	free(a);
}

void copy_matrix(double **a, double **b, int n, int m)
{
	int i, j;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void copy_vector(double *a, double *b, int n)
{
	int i;

	for (i=0; i<n; i++) {
		b[i] = a[i];
	}
}

void m_m_add(double **a, double **b, double **c, int n, int m)
{
	int i, j;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void v_v_add(double *a, double *b, double *c, int n)
{
	int i;

	for (i=0; i<n; i++) {
		c[i] = a[i] + b[i];
	}
}

void m_m_sub(double **a, double **b, double **c, int n, int m)
{
	int i, j;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
}

void v_v_sub(double *a, double *b, double *c, int n)
{
	int i;

	for (i=0; i<n; i++) {
		c[i] = a[i] - b[i];
	}
}

void m_s_mul(double **a, double b, double **c, int n, int m)
{
	int i, j;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			c[i][j] = a[i][j] * b;
		}
	}
}

void v_s_mul(double *a, double b, double *c, int n)
{
	int i;

	for (i=0; i<n; i++) {
		c[i] = a[i] * b;
	}
}

void m_v_mul(double **a, double *b, double *c, int n, int m)
{
	int i, j;
	double tmp;

	for (i=0; i<n; i++) {
		tmp = 0.;
		for (j=0; j<m; j++) {
			tmp += a[i][j] * b[j];
		}
		c[i] = tmp;
	}
}

// a: n x m, b: m x s, c: n x s
void m_m_mul(double **a, double **b, double **c, int n, int m, int s)
{
	int i, j, k;
	double tmp;

	for (i=0; i<n; i++) {
		for (j=0; j<s; j++) {
			tmp = 0;
			for (k=0; k<m; k++) {
				tmp += a[i][k] * b[k][j];
			}
			c[i][j] = tmp;
		}
	}
}

double inner_product(double *a, double *b, int n)
{
	int i;
	double r;

	r = 0;
	for (i=0; i<n; i++) r += a[i] * b[i];

	return r;
}

void print_matrix(double **a, int n, int m)
{
	int i, j;

	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			printf("[%d,%d]: %.15g\n", i, j, a[i][j]);
		}
	}
}

void print_vector(double *a, int n)
{
	int i;

	for (i=0; i<n; i++) {
		printf("[%d]: %.15g\n", i, a[i]);
	}
}

int gauss(double **a, double *b, int n)
{
	int i, j, k;
	double tmp;
	int p_num;
	double p_max;

	for (k=0; k<n-1; k++) {
		p_num = -1;
		p_max = 0.;
		for (i=k; i<n; i++) {
			tmp = fabs(a[i][k]);
			if (tmp > p_max) {
				p_max = tmp;
				p_num = i;
			}
		}
		if (p_num == -1) {
			return 0;
		}

		for (i=k; i<n; i++) {
			tmp = a[k][i];
			a[k][i] = a[p_num][i];
			a[p_num][i] = tmp;
		}
		tmp = b[k];
		b[k] = b[p_num];
		b[p_num] = tmp;

		for (i=k+1; i<n; i++) {
			tmp = a[i][k] / a[k][k];
			for (j=k; j<n; j++) {
				a[i][j] -= a[k][j] * tmp;
			}
			b[i] -= b[k] * tmp;
		}
	}

	if (a[n-1][n-1] == 0) return 0;

	for (i = n-1; i>=0; i--) {
		for (j = i+1; j<n; j++) {
			b[i] -= a[i][j] * b[j];
		}
		b[i] /= a[i][i];
	}

	return 1;
}
