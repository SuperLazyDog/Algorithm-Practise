// 静态数组栈
#include <stdio.h>
#include <stdlib.h>

struct arrayStack {
  int top;
  int capacity;
  int *array;
};

struct arrayStack *createStack(int capacity);
void deleteStack(struct arrayStack **p);
int isEmptyStack(struct arrayStack *p);
int isFullStack(struct arrayStack *p);
void push(struct arrayStack **s, int data);
int pop(struct arrayStack **s);
void showStack(struct arrayStack *s);

int main(int argc, char const *argv[]) {
  struct arrayStack *stack = NULL;
  stack = createStack(10);
  for (size_t i = 0; i < 10; i++) {
    push(&stack, i);
  }
  for (size_t i = 0; i < 3; i++) {
    pop(&stack);
  }
  showStack(stack);
  deleteStack(&stack);
  return 0;
}

struct arrayStack *createStack(int capacity) {
  struct arrayStack *new = (struct arrayStack *)malloc(sizeof(struct arrayStack));
  new->top = -1;
  new->capacity = capacity;
  new->array = (int *)malloc(sizeof(int) * new->capacity);
  return new;
}

void deleteStack(struct arrayStack **p) {
  if (*p) {
    if((*p)->array) {
      free((*p)->array);
    }
    free(*p);
  }
  *p = NULL;
}

int isEmptyStack(struct arrayStack *p) {
  return p->top < 0;
}
int isFullStack(struct arrayStack *p) {
  return p->top == p->capacity - 1;
}
void push(struct arrayStack **s, int data) {
  if (!*s) {
    *s = createStack(1024);
  }
  if ((*s)->top >= (*s)->capacity - 1) { // 满了
    puts("满栈");
    return;
  }
  (*s)->array[++(*s)->top] = data;
}

int pop(struct arrayStack **s) {
  if (!*s) {
    return -1;
  }
  if ((*s)->top < 0) {
    puts("空栈");
    return -2;
  }
  return (*s)->array[(*s)->top--];
}

void showStack(struct arrayStack *s) {
  for (int i = 0; i < s->top; i++) {
    printf("stack[%d]: %d\n", i, s->array[i]);
  }
}
