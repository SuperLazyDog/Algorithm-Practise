// 把循环链表二等分, 长度为奇数时多的放在分出来的第一个
// typedef struct circleNode {
//   int data;
//   struct circleNode *next;
// } CircleNode;
// CircleNode *newCircleNode(int data);
// void delete(CircleNode **head);
// void insertAtEnd(CircleNode **head, int data);
// void insertAtBegin(CircleNode **head, int data);
// void deleteFirst(CircleNode **head);
// void deleteLast(CircleNode **head);
// void showNodes(CircleNode *head);
void splitList(CircleNode *head, CircleNode **l, CircleNode **r) {
  int count = 0, lLimit;
  CircleNode *temp = head;
  if (!head) {
    return;
  }
  do {
    count++;
    temp = temp->next;
  } while(temp != head);
  temp = head;
  lLimit = count/2 + count%2;
  *l = head;
  for (int i = 1; i < lLimit; i++) {
    temp = temp->next;
  }
  *r = temp->next;
  temp->next = *l;
  temp = *r;
  while (temp->next != head) {
    temp = temp->next;
  }
  temp->next = *r;
}

// TODO: p76 floyd法
void splitList(CircleNode *head, CircleNode **r) {
  CircleNode *slow, *fast; // fast应为最后一个, slow为前一半最后一个
  slow = fast = head;
  if (!head) {
    return;
  }
  while (fast->next != head && fast->next->next != head) {
    fast = fast->next->next;
    slow = slow->next;
  }
  if (fast->next->next == head) { // 有偶数个
    fast = fast->next;
  }
  *r = slow->next;
  slow->next = head;
  fast->next = *r;
}
