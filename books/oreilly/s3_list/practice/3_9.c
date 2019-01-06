// 确认链表是循环的还是以NULL结束
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

int getListType(ListNode *head) {
  // 0: 线性  1: 循环
  ListNode *slow, *fast;
  slow = fast = head;
  while (slow && fast) {
    fast = fast->next;
    if (fast == slow) {
      return 1;
    }
    if (!fast) {
      return 0;
    }
    fast = fast->next;
    if (fast == slow) {
      return 1;
    }
    slow = slow->next;
  }
  return 0;
}
