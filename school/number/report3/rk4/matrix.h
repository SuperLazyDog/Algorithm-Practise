#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **alloc_matrix(int n, int m);
double *alloc_vector(int n);
void free_matrix(double **a);
void free_vector(double *a);
void copy_matrix(double **a, double **b, int n, int m);
void copy_vector(double *a, double *b, int n);
void m_m_add(double **a, double **b, double **c, int n, int m);
void v_v_add(double *a, double *b, double *c, int n);
void m_m_sub(double **a, double **b, double **c, int n, int m);
void v_v_sub(double *a, double *b, double *c, int n);
void m_s_mul(double **a, double b, double **c, int n, int m);
void v_s_mul(double *a, double b, double *c, int n);
void m_v_mul(double **a, double *b, double *c, int n, int m);
void m_m_mul(double **a, double **b, double **c, int n, int m, int s);
double inner_product(double *a, double *b, int n);
void print_matrix(double **a, int n, int m);
void print_vector(double *a, int n);
int gauss(double **a, double *b, int n);
