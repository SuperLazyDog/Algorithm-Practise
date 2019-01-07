// 链表实现队列
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct lN {
  int data;
  struct lN *next;
} ListNode;

typedef struct q {
  ListNode *front;
  ListNode *rear;
} Queue;

Queue *createQueue();
void deleteQueue(Queue **q);
void showQueue(Queue *q);
int isEmptyQueue(Queue *q);
int top(Queue *q);
void enQueue(Queue *q, int data);
int deQueue(Queue *q);

int main(int argc, char const *argv[]) {
  Queue *q = createQueue();
  for (size_t i = 0; i < 20; i++) {
    enQueue(q, i);
  }
  showQueue(q);

  for (size_t i = 0; i < 10; i++) {
    deQueue(q);
  }
  showQueue(q);

  deleteQueue(&q);
  return 0;
}

Queue *createQueue() {
  Queue *new = (Queue *)malloc(sizeof(Queue));
  new->front = new->rear = NULL;
  return new;
}

void deleteQueue(Queue **q) {
  ListNode *temp, *temp2;
  if (!q) {
    return;
  }
  if (*q) {
    temp = (*q)->front;
    while (temp) {
      temp2 = temp->next;
      free(temp);
      temp = temp2;
    }
    free(*q);
  }
  *q = NULL;
}

void showQueue(Queue *q) {
  ListNode *temp = q->front;
  int i = 0;
  while (temp) {
    printf("queue[%d]: %d\n", i++, temp->data);
    temp = temp->next;
  }
  printf("size: %d\n", i);
  puts("");
}

int isEmptyQueue(Queue *q) {
  return q->front == NULL;
}

int top(Queue *q) {
  if (q->front) {
    return q->front->data;
  }
  return INT_MIN;
}

void enQueue(Queue *q, int data) {
  ListNode *new = (ListNode *)malloc(sizeof(ListNode));
  new->next = NULL;
  new->data = data;
  if (q->front) { // 非空
    q->rear->next = new;
    q->rear = new;
  } else {
    q->front = q->rear = new;
  }
}

int deQueue(Queue *q) {
  int data = INT_MIN;
  ListNode *temp;
  if (q->front) {
    data = q->front->data;
    if (q->front->next) {
      temp = q->front->next;
      free(q->front);
      q->front = temp;
    } else { // 拿了后为空
      q->front = q->rear = NULL;
    }
  }
  return data;
}
