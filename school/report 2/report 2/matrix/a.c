//
//  a.c
//  report 2
//
//  Created by 徐伟达 on 2018/7/13.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "matrix.h"

#define LIMIT 1e-10

void f(double *x, double *y) {
	y[0] = 2*x[3]*x[3] + 2*x[2]*x[2] + 2*x[1]*x[1] + x[0]*x[0] - x[0];
	y[1] = 2*x[3]*x[2] + 2*x[2]*x[1] + 2*x[1]*x[0] - x[1];
	y[2] = 2*x[3]*x[1] + 2*x[2]*x[0] + x[1]*x[1]   - x[2];
	y[3] = 2*x[3]	   + 2*x[2]		 + 2*x[1]	   + x[0]	   - 1;
}

void df(double *x, double **m) {
	m[0][0] = 2*x[0] - 1;
	m[0][1] = 4*x[1];
	m[0][2] = 4*x[2];
	m[0][3] = 4*x[3];
	
	m[1][0] = 2*x[1];
	m[1][1] = 2*x[2] + 2*x[0] - 1;
	m[1][2] = 2*x[3] + 2*x[1];
	m[1][3] = 2*x[2];
	
	m[2][0] = 2*x[2];
	m[2][1] = 2*x[3] + 2*x[1];
	m[2][2] = 2*x[0] - 1;
	m[2][3] = 2*x[1];
	
	m[3][0] = 1;
	m[3][1] = 2;
	m[3][2] = 2;
	m[3][3] = 2;
}

double norm_vector(double *x, int n) {
	double s;
	int i;
	
	s = 0;
	for (i=0; i<n; i++) {
		s += x[i] * x[i];
	}
	
	return sqrt(s);
}

int main()
{
	double *x, *y;
	double **m;

	x = alloc_vector(4);
	y = alloc_vector(4);
	m = alloc_matrix(4, 4);

	x[0] = x[1] = x[2] = x[3] = 0;
	
	while (1) {
		f(x, y);
		df(x, m);
		gauss(m, y, 4);
		v_v_sub(x, y, x, 4);
		if (norm_vector(y, 4) < LIMIT) {
			break;
		}
	}
	
	
	print_vector(x, 4);
	
	free_vector(x);
	free_vector(y);
	free_matrix(m);
	
	return 0;
}

