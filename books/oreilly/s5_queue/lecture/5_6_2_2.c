// 动态循环数组实现
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

int main(int argc, char const *argv[]) {
  DoubleArrayQueue *q = createQueue();
  for (int i = 0; i < 20; i++) {
    enQueue(q, i);
  }
  showQueue(q);

  for (int i = 0; i < 10; i++) {
    deQueue(q);
  }
  showQueue(q);

  for (int i = 0; i < 40; i++) {
    enQueue(q, i*100);
  }
  showQueue(q);
  return 0;
}

DoubleArrayQueue *createQueue() {
  DoubleArrayQueue *q = (DoubleArrayQueue *)malloc(sizeof(DoubleArrayQueue));
  q->capacity = 1;
  q->front = q->rear = -1;
  q->array = (int *)malloc(q->capacity * sizeof(int));
  return q;
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
    return -1;
  } else {
    if (q->front <= q->rear) {
      return q->rear - q->front + 1;
    } else {
      return q->capacity - (q->front - q->rear - 1);
    }
  }
}

void showQueue(DoubleArrayQueue *q) {
  printf("q->capacity: %d, size: %d, front: %d, rear: %d\n", q->capacity, queueSize(q), q->front, q->rear);
  if (q->front != -1) {
    int i, j, k = 0;
    i = q->front % q->capacity;
    j = q->rear % q->capacity;
    while (i != j) {
      printf("queue[%d]: %d\n", k++, q->array[i]);
      i = (i + 1) % q->capacity;
    }
    printf("queue[%d]: %d\n", k++, q->array[i]);
  } else {
    puts("queue is empty");
  }
  puts("");puts("");
}

int isEmptyQueue(DoubleArrayQueue *q) {
  return q->front == -1;
}

int isFullQueue(DoubleArrayQueue *q) {
  return ((q->rear + 1) % q->capacity == q->front);
}

void enQueue(DoubleArrayQueue *q, int data) {
  if ((q->rear + 1) % q->capacity == q->front) {
    // TODO: note [这里用 realloc 会出错]
    int size = q->capacity, *temp;
    q->capacity *= 2;
    temp = (int *)malloc(q->capacity * sizeof(int));
    for (int i = 0; i < size; i++) {
      temp[i] = q->array[i];
    }
    free(q->array);
    q->array = temp;
    if (q->front > q->rear) {
      // TODO: note [书上是到 q->front, 但是有效数据只到 q->rear]
      for (int i = 0; i <= q->rear; i++) {
        q->array[i+size] = q->array[i];
      }
      q->rear += size;
    }
  }
  q->rear = ((q->rear + 1) % q->capacity);
  q->array[q->rear] = data;
  if (q->front == -1) {
    q->front = q->rear;
  }
}

int deQueue(DoubleArrayQueue *q) {
  int data;
  if (q->front == -1) {
    puts("queue is empty, cannot dequeue");
    return INT_MIN;
  }
  data = q->array[q->front];
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % q->capacity;
  }
  return data;
}
