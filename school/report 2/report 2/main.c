//
//  main.c
//  report 2
//
//  Created by 徐伟达 on 2018/7/13.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "matrix.h"

#define LIMIT 1e-10
#define X_COUNT 4
#define Y_COUNT 4
#define INITIAL_X 0.7
#define INTERVAL -0.04

// vectorを格納するデータ構造
struct Vectors {
	int capacity;
	int count;
	double** vectors;
};

// 関数プロトタイプ
void f(double *x, double *y);
void df(double *x, double **m);
double norm_vector(double *x, int n);
// VectorsのADT
struct Vectors *createVectors(void);
void freeVectors(struct Vectors *vs);
void pushVector(struct Vectors *vs, double *v);
int vectorCount(struct Vectors *vs);
int isEqual(double *v1, double *v2, int count);
int isInclude(struct Vectors *vs, double *v);
// 初期値の設定
void initData(double *v, int step);

int main()
{
	double *x, *y;
	double **m;
	int i = 0, step = 0;
	struct Vectors *vs = createVectors();
	freeVectors(vs);
	vs = createVectors();
	
	while (vectorCount(vs) < 5) {
		x = alloc_vector(X_COUNT);
		y = alloc_vector(Y_COUNT);
		m = alloc_matrix(X_COUNT, Y_COUNT);
		
		initData(x, step);
		
		while (1) {
			f(x, y);
			df(x, m);
			gauss(m, y, X_COUNT);
			v_v_sub(x, y, x, X_COUNT);
			if (norm_vector(y, Y_COUNT) < LIMIT) {
				pushVector(vs, x);
				break;
			}
		}
		free_vector(x);
		free_vector(y);
		free_matrix(m);
		step++;
	}
	
	for (i = 0; i < vs->count; i++) {
		printf("%d\n", i);
		print_vector(vs->vectors[i], X_COUNT);
	}
	freeVectors(vs);
	
	return 0;
}

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

struct Vectors *createVectors() {
	struct Vectors *vs = (struct Vectors *)malloc(sizeof(struct Vectors));
	vs->capacity = 1;
	vs->count = 0;
	vs->vectors = (double **)malloc(sizeof(double *)*vs->capacity);
	return vs;
}

void freeVectors(struct Vectors *vs) {
	if (vs->vectors) {
		for (int i = 0; i < vs->count; i++) {
			free(vs->vectors[i]);
		}
		free(vs->vectors);
	}
	free(vs);
}

void pushVector(struct Vectors *vs, double *v) {
	double *temp = (double *)malloc(sizeof(double *)*X_COUNT);
	if (isInclude(vs, v)) {
		return;
	}
	
	if (vs->capacity == vs->count) {
		vs->capacity *= 2;
		vs->vectors = (double **)realloc(vs->vectors, sizeof(double *)*vs->capacity);
	}
	for (int i = 0; i < X_COUNT; i++) {
		temp[i] = v[i];
	}
	vs->vectors[vs->count] = temp;
	vs->count++;
}

int vectorCount(struct Vectors *vs) {
	return vs->count;
}

int isEqual(double *v1, double *v2, int count) {
	for (int i = 0; i < count; i++) {
		if (v1[i] != v2[i]) {
			return 0;
		}
	}
	return 1;
}

int isInclude(struct Vectors *vs, double *v) {
	for (int i = 0; i < vs->count; i++) {
		if (isEqual(vs->vectors[i], v, X_COUNT)) {
			return 1;
		}
	}
	return 0;
}

void initData(double *v, int step) {
	int temp;
	for (int i = 0; i < X_COUNT; i++) {
		temp = step - i;
		temp = temp >= 0 ? temp : 0;

		v[i] = INITIAL_X + (double)temp*INTERVAL;
		if (v[i] < -1) {
			v[i] = -1;
		} else if (v[i] > 1) {
			v[i] = 1;
		}
	}
}
