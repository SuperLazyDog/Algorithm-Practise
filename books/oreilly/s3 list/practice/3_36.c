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
int isPalindrome(ListNode *head) {
  ListNode *slow, *fast, *rStart, *rNext = NULL, *temp;
  int result = 1;
  slow = fast = head;
  if (!head) {
    result = 0;
    return result;
  }
  while (fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  if (fast->next && !fast->next->next) { // 偶数个
    fast = fast->next;
  }
  rStart = slow->next;
  while (rStart) {
    temp = rStart->next;
    rStart->next = rNext;
    rNext = rStart;
    rStart = temp;
  }
  rStart = rNext;
  temp = head;
  while (rStart) {
    if (temp->data != rStart->data) {
      result = 0;
      break;
    }
    temp = temp->next;
    rStart = rStart->next;
  }
  // 右半边复原
  rStart = rNext;
  rNext = NULL;
  while (rStart) {
    temp = rStart->next;
    rStart->next = rNext;
    rNext = rStart;
    rStart = temp;
  }
  slow->next = rNext;
  return result;
}
