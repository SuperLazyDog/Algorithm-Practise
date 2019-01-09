// 把队列反过来
// typedef struct lN {
//   int data;
//   struct lN *next;
// } ListNode;
//
// typedef struct q {
//   ListNode *front;
//   ListNode *rear;
// } Queue;
//
// Queue *createQueue();
// void deleteQueue(Queue **q);
// void showQueue(Queue *q);
// int isEmptyQueue(Queue *q);
// int top(Queue *q);
// void enQueue(Queue *q, int data);
// int deQueue(Queue *q);

// 递归版
void reverseQueue(Queue *q) {
  if (isEmptyQueue(q)) {
    return;
  }
  int data = deQueue(q);
  reverseQueue(q);
  enQueue(q, data);
}

// 非递归版
void reverseQueue(Queue *q) {
  int count = 0;
  ListNode *temp = q->front;
  while (temp) {
    count++;
    temp = temp->next;
  }
  int datas[count];
  temp = q->front;
  count = 0;
  while (temp) {
    datas[count++] = temp->data;
    temp = temp->next;
  }
  temp = q->front;
  while (temp) {
    temp->data = datas[--count];
    temp = temp->next;
  }
}
