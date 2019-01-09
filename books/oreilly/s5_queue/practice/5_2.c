// 用两个栈实现队列
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s {
  int head, capacity;
  int *data;
} Stack;
Stack *createStack();
void deleteStack(Stack **s);
void showStack(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);

typedef struct q {
  Stack *s1;
  Stack *s2;
} Queue;
Queue *createQueue();
void deleteQueue(Queue **q);
void showQueue(Queue *q);
void enQueue(Queue *q, int data);
int deQueue (Queue *q);


int main(int argc, char const *argv[]) {
  // Stack *s = createStack();
  // for (int i = 0; i < 20; i++) {
  //   push(s, i);
  // }
  // showStack(s);
  // for (int i = 0; i < 10; i++) {
  //   pop(s);
  // }
  // showStack(s);
  // deleteStack(&s);
  Queue *q = createQueue();
  for (size_t i = 0; i < 20; i++) {
    enQueue(q, i);
  }
  showQueue(q);
  for (size_t i = 0; i < 10; i++) {
    deQueue(q);
  }
  showQueue(q);
  for (size_t i = 20; i < 30; i++) {
    enQueue(q, i);
  }
  showQueue(q);
  deleteQueue(&q);
  return 0;
}

Stack *createStack() {
  Stack *new = (Stack *)malloc(sizeof(Stack));
  new->head = -1;
  new->capacity = 1;
  new->data = (int *)malloc(sizeof(int)*new->capacity);
  return new;
}

void deleteStack(Stack **s) {
  if (!s) {
    return;
  }
  if (*s) {
    if ((*s)->data) {
      free((*s)->data);
    }
    free(*s);
  }
  *s = NULL;
}

void showStack(Stack *s) {
  if (s->head < 0) {
    puts("stack is empty");
  } else {
    for (int i = s->head; i >= 0; i--) {
      printf("stack[%d]: %d\n", i, s->data[i]);
    }
  }
  puts("");puts("");
}

void push(Stack *s, int data) {
  int *temp, size;
  if (s->head >= s->capacity-1) { // 已满
    size = s->capacity;
    s->capacity  *= 2;
    temp = (int *)malloc(sizeof(int)*s->capacity);
    for (size_t i = 0; i < size; i++) {
      temp[i] = s->data[i];
    }
    free(s->data);
    s->data = temp;
  }
  s->data[++(s->head)] = data;
}

int pop(Stack *s) {
  if (s->head < 0) {
    return INT_MIN;
  }
  return s->data[s->head--];
}

//-----------------------------------------------------------------------------
Queue *createQueue() {
  Queue *new = (Queue *)malloc(sizeof(Queue));
  new->s1 = createStack();
  new->s2 = createStack();
  return new;
}

void deleteQueue(Queue **q) {
  if (!q) {
    return;
  }
  if (*q) {
    deleteStack(&((*q)->s1));
    deleteStack(&((*q)->s2));
    free(*q);
  }
  *q = NULL;
}

void showQueue(Queue *q) {
  int j = 0;
  if (q->s2) {
    for (int i = q->s2->head; i >= 0; i--) {
      printf("queue[%d]: %d\n", j++, q->s2->data[i]);
    }
  }
  if (q->s1) {
    for (int i = 0; i <= q->s1->head; i++) {
      printf("queue[%d]: %d\n", j++, q->s1->data[i]);
    }
  }
  printf("count: %d\n", j);
  puts("");
}

void enQueue(Queue *q, int data) {
  push(q->s1, data);
}

int deQueue (Queue *q) {
  if (q->s2->head == -1) {
    if (q->s1->head == -1) {
      puts("empty queue");
      return INT_MIN;
    } else {
      while (q->s1->head != -1) {
        push(q->s2, pop(q->s1));
      }
    }
  }
  return pop(q->s2);
}
