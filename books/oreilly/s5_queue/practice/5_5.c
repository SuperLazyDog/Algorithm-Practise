// n个元素的队列, 放到栈里, 要求第一个在顶部，其他顺序不变
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct dAQ {
  int front,rear; // 开始都是-1
  int capacity;
  int *array;
} DoubleArrayQueue;

DoubleArrayQueue *createQueue();
void deleteQueue(DoubleArrayQueue **q);
int queueSize(DoubleArrayQueue *q);
void showQueue(DoubleArrayQueue *q);
int isEmptyQueue(DoubleArrayQueue *q);
int isFullQueue(DoubleArrayQueue *q);
void enQueue(DoubleArrayQueue *q, int data);
int deQueue(DoubleArrayQueue *q);

typedef struct s {
  int head, capacity;
  int *data;
} Stack;
Stack *createStack();
void deleteStack(Stack **s);
void showStack(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);

int main(int argc, char const *argv[]) {
  DoubleArrayQueue *q = createQueue();
  Stack *s = createStack();

  for (size_t i = 0; i < 10; i++) {
    enQueue(q, i);
  }
  showQueue(q);
  showStack(s);
  int temp = deQueue(q);
  while (q->front != -1) {
    push(s, deQueue(q));
  }
  push(s, temp);
  showQueue(q);
  showStack(s);
  deleteQueue(&q);
  deleteStack(&s);
  return 0;
}

DoubleArrayQueue *createQueue() {
  DoubleArrayQueue *new = (DoubleArrayQueue *)malloc(sizeof(DoubleArrayQueue));
  new->capacity = 1;
  new->front = new->rear = -1;
  new->array = (int *)malloc(sizeof(int)*new->capacity);
  return new;
}

void deleteQueue(DoubleArrayQueue **q) {
  if (!q) {
    return;
  }
  if (*q) {
    if ((*q)->array) {
      free((*q)->array);
    }
    free(*q);
  }
  *q = NULL;
}

int queueSize(DoubleArrayQueue *q) {
  if (q->front == -1) {
    return 0;
  }
  if (q->rear >= q->front) {
    return q->rear - q->front + 1;
  } else {
    return q->capacity - (q->front - q->rear - 1);
  }
}
void showQueue(DoubleArrayQueue *q) {
  int s = q->front, i = 0;
  printf("size: %d\n", queueSize(q));
  if (s == -1) {
    return;
  }
  do {
    printf("queue[%d]: %d\n", i++, q->array[s]);
    s = (s+1)%q->capacity;
  } while(s != q->rear);
  printf("queue[%d]: %d\n", i++, q->array[s]);
  puts("");puts("");
}

int isEmptyQueue(DoubleArrayQueue *q) {
  return q->front == -1;
}
int isFullQueue(DoubleArrayQueue *q) {
  return (q->front+1)%q->capacity == q->rear;
}

void enQueue(DoubleArrayQueue *q, int data) {
  if (queueSize(q) >= q->capacity) {
    int size = q->capacity, *temp;
    q->capacity *= 2;
    temp = (int *)malloc(sizeof(int)*q->capacity);
    for (int i = 0; i < size; i++) {
      temp[i] = q->array[i];
    }
    if (q->front > q->rear) {
      for (int i = 0; i <= q->rear; i++) {
        temp[i + size] = temp[i];
      }
      q->rear = (q->rear + size) % q->capacity;
    }
    free(q->array);
    q->array = temp;
  }
  q->rear = (q->rear + 1) % q->capacity;
  q->array[q->rear] = data;
  if (q->front == -1) {
    q->front = q->rear;
  }
}

int deQueue(DoubleArrayQueue *q) {
  if (q->front == -1) {
    return INT_MIN;
  }
  int data = q->array[q->front];
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % q->capacity;
  }
  return data;
}

Stack *createStack() {
  Stack *new = (Stack *)malloc(sizeof(Stack));
  new->capacity = 1;
  new->head = -1;
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
  int j = 0;
  for (int i = s->head; i >= 0; i--) {
    printf("stack[%d]: %d\n", j++, s->data[i]);
  }
  printf("count: %d\n", j);
  puts("");puts("");
}
void push(Stack *s, int data) {
  if (s->head + 1 >= s->capacity) {
    int size = s->capacity, *temp;
    s->capacity *= 2;
    temp = (int *)malloc(sizeof(int)*s->capacity);
    for (int i = 0; i < size; i++) {
      temp[i] = s->data[i];
    }
    free(s->data);
    s->data = temp;
  }
  s->data[++s->head] = data;
}
int pop(Stack *s) {
  if (s->head < 0) {
    return INT_MIN;
  }
  return s->data[s->head--];
}
