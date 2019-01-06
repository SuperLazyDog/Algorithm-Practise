// 确认带循环的链表的循环起点
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

ListNode *getCircleStartPoint(ListNode *head, ListNode *fast) {
  ListNode *slow = head, *temp = fast;
  while (temp != slow) {
    slow = slow->next;
    temp = temp->next;
  }
  return slow;
}
