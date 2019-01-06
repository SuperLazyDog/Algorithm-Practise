// 静态循环数组实现
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct aQ {
  int front,rear; // 开始都是-1
  int capacity;
  int *array;
} ArrayQueue;

ArrayQueue *createQueue(int size);
void deleteQueue(ArrayQueue **q);
int queueSize(ArrayQueue *q);
void showQueue(ArrayQueue *q);
int isEmptyQueue(ArrayQueue *q);
int isFullQueue(ArrayQueue *q);
void enQueue(ArrayQueue *q, int data);
int deQueue(ArrayQueue *q);

int main(int argc, char const *argv[]) {
  ArrayQueue *q = createQueue(20);
  int size;
  showQueue(q);
  for (int i = 0; i < 20; i++) {
    enQueue(q, i);
  }
  showQueue(q);
  for (int i = 0; i < 5; i++) {
    deQueue(q);
  }
  showQueue(q);
  for (int i = 0; i < 4; i++) {
    enQueue(q, i*100);
  }
  showQueue(q);
  size = queueSize(q);
  for (int i = 0; i < size; i++) {
    deQueue(q);
  }
  showQueue(q);
  deleteQueue(&q);
  return 0;
}

ArrayQueue *createQueue(int size) {
  ArrayQueue *q = (ArrayQueue *)malloc(sizeof(ArrayQueue));
  if (size <= 0) {
    size = 1024;
  }
  q->front = q->rear = -1;
  q->capacity = size;
  q->array = (int *)malloc(q->capacity*sizeof(int));
  return q;
}
void deleteQueue(ArrayQueue **q) {
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

int queueSize(ArrayQueue *q) {
  if (q->front <= q->rear) {
    return q->rear - q->front + 1;
  } else {
    return q->capacity - (q->front - q->rear - 1);
  }
  // return (q->capacity-(q->front-q->rear-1)) % q->capacity; // 书上的, 有错误
}

void showQueue(ArrayQueue *q) {
  int i, j = 0, k;
  printf("q->capacity: %d, size: %d, front: %d, rear: %d\n", q->capacity, queueSize(q), q->front, q->rear);
  if (!isEmptyQueue(q)) {
    i = q->front % q->capacity;
    k = q->rear % q->capacity;
    while (i != k) {
      printf("queue[%d]: %d\n", j++, q->array[i]);
      i = (i + 1) % q->capacity;
    }
    printf("queue[%d]: %d\n", j++, q->array[i]);
  } else {
    printf("queue is empty\n");
  }
  puts("");puts("");
}

int isEmptyQueue(ArrayQueue *q) {
  return q->front == -1;
}
int isFullQueue(ArrayQueue *q) {
  return (q->rear + 1) % q->capacity == q->front;
}

void enQueue(ArrayQueue *q, int data) {
  if (isFullQueue(q)) {
    printf("queue is full, cannot enqueue %d", data);
    return;
  }
  q->rear = (q->rear + 1) % q->capacity;
  q->array[q->rear] = data;
  if (q->front == -1) { // 本来是空序列则开头设置为第一个元素
    q->front = q->rear;
  }
}

int deQueue(ArrayQueue *q) {
  if (isEmptyQueue(q)) {
    puts("queue is empty, cannot dequeue");
    return INT_MIN;
  }
  int result = q->array[q->front];
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % q->capacity;
  }
  return result;
}
