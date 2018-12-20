// 动态数组栈  满了容量变两倍
#include <stdio.h>
#include <stdlib.h>

typedef struct doubleArrayStack {
  int top;
  int capacity;
  int *datas;
} DoubleArrayStack;

DoubleArrayStack *createStack(int capacity);
void deleteStack(DoubleArrayStack **p);
void push(DoubleArrayStack **p, int data);
int pop(DoubleArrayStack *p);
int top(DoubleArrayStack *p);
int isFullStack(DoubleArrayStack *p);
int isEmptyStack(DoubleArrayStack *p);
void showStack(DoubleArrayStack *p);

int main(int argc, char const *argv[]) {
  DoubleArrayStack *new = NULL;
  for (size_t i = 0; i < 10; i++) {
    push(&new, i);
  }
  showStack(new);
  pop(new);
  pop(new);
  pop(new);
  showStack(new);
  deleteStack(&new);
  return 0;
}

DoubleArrayStack *createStack(int capacity) {
  DoubleArrayStack *new = (DoubleArrayStack *)malloc(sizeof(DoubleArrayStack));
  new->capacity = capacity;
  new->top = -1;
  new->datas = (int *)malloc(sizeof(int)*new->capacity);
  return new;
}

void deleteStack(DoubleArrayStack **p) {
  if (!p) {
    return;
  }
  if (*p) {
    if((*p)->datas) {
      free((*p)->datas);
    }
    free(*p);
  }
  *p = NULL;
}

void push(DoubleArrayStack **p, int data) {
  if (!p) {
    return;
  }
  if (!*p) {
    *p = createStack(1);
  }
  if ((*p)->top >= (*p)->capacity - 1) { // 容量已满
    (*p)->capacity = (*p)->capacity * 2;
    (*p)->datas = (int *)realloc((*p)->datas, sizeof(int)*(*p)->capacity);
  }
  (*p)->datas[++(*p)->top] = data;
}

int pop(DoubleArrayStack *p) {
  if (!p) {
    return -1;
  }
  if (p->top < 0) {
    puts("空栈");
    return -2;
  }
  return p->datas[p->top--];
}

int top(DoubleArrayStack *p) {
  if (!p) {
    return -1;
  }
  if (p->top < 0) {
    puts("空栈");
    return -2;
  }
  return p->datas[p->top];
}

int isFullStack(DoubleArrayStack *p) {
  if (!p) {
    puts("栈不存在");
    return 0;
  }
  return p->top >= p->capacity - 1;
}

int isEmptyStack(DoubleArrayStack *p) {
  if (!p) {
    puts("栈不存在");
    return 0;
  }
  return p->top < 0;
}

void showStack(DoubleArrayStack *p) {
  for (size_t i = 0; i < p->top; i++) {
    printf("stack[%zu]: %d\n", i, p->datas[i]);
  }
  puts("");puts("");
}
