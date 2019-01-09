// 用两个队列实现栈
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct q {
  int front, rear, capacity;
  int *data;
} Queue;

Queue *createQueue();
void deleteQueue(Queue **q);
void showQueue(Queue *q);
int queueSize(Queue *q);
void enQueue(Queue *q, int data);
int deQueue(Queue *q);
int topQueue(Queue *q);

typedef struct s {
  Queue *q1;
  Queue *q2;
} Stack;
Stack *createStack();
void deleteStack(Stack **s);
void showStack(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);
int top(Stack *s);

int main(int argc, char const *argv[]) {
  Stack *s = createStack();
  for (size_t i = 0; i < 20; i++) {
    push(s, i);
  }
  showStack(s);
  for (size_t i = 0; i < 5; i++) {
    pop(s);
  }
  showStack(s);
  for (size_t i = 30; i < 40; i++) {
    push(s, i);
  }
  showStack(s);
  deleteStack(&s);
  return 0;
}

Queue *createQueue() {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->capacity = 1;
  q->front = q->rear = -1;
  q->data = (int *)malloc(sizeof(int)*q->capacity);
  return q;
}

void deleteQueue(Queue **q) {
  if (!q) {
    return;
  }
  if (*q) {
    if ((*q)->data) {
      free((*q)->data);
    }
    free(*q);
  }
  *q = NULL;
}

void showQueue(Queue *q) {
  printf("size: %d\n", queueSize(q));
  int j = 0, si = q->front, oi = q->rear;
  if (q->front != -1) {
    while (si != oi) {
      printf("queue[%d]: %d\n", j++, q->data[si]);
      si = (si + 1) % q->capacity;
    }
    printf("queue[%d]: %d\n", j++, q->data[si]);
  }
  puts("");puts("");
}

int queueSize(Queue *q) {
  if (q->front == -1) {
    return 0;
  } else {
    if (q->front <= q->rear) {
      return q->rear - q->front + 1;
    } else {
      return q->capacity - (q->front - q->rear - 1);
    }
  }
}

void enQueue(Queue *q, int data) {
  int isFull = (q->rear + 1) % q->capacity == q->front;
  if (isFull) {
    int size = q->capacity, *temp, si = q->front, oi = q->rear;
    q->capacity *= 2;
    temp = (int *)malloc(sizeof(int)*q->capacity);
    for (size_t i = 0; i < size; i++) {
      temp[i] = q->data[i];
    }
    if (q->front > q->rear) {
      for (size_t i = 0; i <= q->rear; i++) {
        temp[i+size] = temp[i];
      }
    }
    free(q->data);
    q->data = temp;
  }
  q->rear = (q->rear + 1) % q->capacity;
  if (q->front == -1) {
    q->front = q->rear;
  }
  q->data[q->rear] = data;
}

int deQueue(Queue *q) {
  int isEmpty = q->front == -1, data;
  if (isEmpty) {
    puts("queue empty, cannot dequeue");
    return INT_MIN;
  }
  data = q->data[q->front];
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % q->capacity;
  }

  return data;
}

int topQueue(Queue *q) {
  int isEmpty = q->front == -1;
  if (isEmpty) {
    puts("queue empty, cannot dequeue");
    return INT_MIN;
  }
  return q->data[q->front];
}
//-----------------------------------------------------------------------------
Stack *createStack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->q1 = createQueue();
  s->q2 = createQueue();
  return s;
}

void deleteStack(Stack **s) {
  if (!s) {
    return;
  }
  if (*s) {
    deleteQueue(&((*s)->q1));
    deleteQueue(&((*s)->q2));
    free(*s);
  }
  *s = NULL;
}

void showStack(Stack *s) {
  int q1Size = queueSize(s->q1), q2Size = queueSize(s->q2);
  int j = 0;
  if (s->q1->front != -1) {
    int *temp = (int *)malloc(sizeof(int)*q1Size), k = 0, si = s->q1->front, oi = s->q1->rear;
    while (k < q1Size) {
      temp[k++] = s->q1->data[si];
      si = (si + 1) % s->q1->capacity;
    }
    while (k > 0) {
      printf("stack[%d]: %d\n", j++, temp[--k]);
    }
    free(temp);
  }
  if (s->q2->front != -1) {
    int si = s->q2->front, oi = s->q2->rear;
    while (si != oi) {
      printf("stack[%d]: %d\n", j++, s->q2->data[si]);
      si = (si + 1) % s->q2->capacity;
    }
    printf("stack[%d]: %d\n", j++, s->q2->data[si]);
  }
  puts("");puts("");
}

void push(Stack *s, int data) {
  // enQueue(s->q1, data);
  int q1Size = queueSize(s->q1);
  if (q1Size == s->q1->capacity) {
    s->q1->capacity *= 2;
    int *temp = (int *)malloc(sizeof(int)*s->q1->capacity);
    for (size_t i = 0; i < q1Size; i++) {
      temp[i] = s->q1->data[i];
    }
    if (s->q1->front > s->q1->rear) {
      for (size_t i = 0; i <= s->q1->rear; i++) {
        temp[i+q1Size] = temp[i];
      }
    }
    free(s->q1->data);
    s->q1->data = temp;
  }
  s->q1->rear = (s->q1->rear + 1) % s->q1->capacity;
  if (s->q1->front == -1) {
    s->q1->front = s->q1->rear;
  }
  s->q1->data[s->q1->rear] = data;
}

int pop(Stack *s) {
  if (s->q2->front == -1) {
    if (s->q1->front == -1) {
      puts("empty stack, cannot pop");
      return INT_MIN;
    } else {
      int count, *temp, j = 0;
      if (s->q1->front > s->q1->rear) {
        count = s->q1->capacity - (s->q1->front - s->q1->rear -1);
      } else {
        count = s->q1->rear - s->q1->front + 1;
      }
      temp = (int *)malloc(sizeof(int)*count);
      while (s->q1->front != -1) {
        temp[j++] = deQueue(s->q1);
      }
      while (j > 0) {
        enQueue(s->q2, temp[--j]);
      }
      free(temp);
    }
  }
  return deQueue(s->q2);
}

int top(Stack *s) {
  if (s->q2->front == -1) {
    if (s->q1->front == -1) {
      puts("empty stack, cannot pop");
      return INT_MIN;
    } else {
      int count, *temp, j = 0;
      if (s->q1->front > s->q1->rear) {
        count = s->q1->capacity - (s->q1->front - s->q1->rear -1);
      } else {
        count = s->q1->rear - s->q1->front + 1;
      }
      temp = (int *)malloc(sizeof(int)*count);
      while (s->q1->front != -1) {
        temp[j++] = deQueue(s->q1);
      }
      while (j > 0) {
        enQueue(s->q2, temp[--j]);
      }
      free(temp);
    }
  }
  return s->q2->data[s->q2->front];
}
