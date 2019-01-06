// 判断单向链表是否是回文, 即正反都一样
// struct listNode {
//   int data;
//   struct listNode *next;
// };
// typedef struct listNode ListNode;
// int listLength(ListNode *head); // 遍历
// void addElement(ListNode **head, int data, int position); // position从0开始
// void deleteElement(ListNode **head, int position);
// ListNode *createList(int data);
// void deleteList(ListNode **p);

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
