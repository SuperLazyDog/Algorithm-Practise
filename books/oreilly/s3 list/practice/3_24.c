// 寻找单向链表的中间点
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

// O(n)
// 以0为起始索引, 中间点在n/2
ListNode *getMiddleNode(ListNode *head) {
  ListNode *temp = head;
  int count = 0;
  while (temp) {
    count++;
    temp = temp->next;
  }
  count = count/2;
  for (size_t i = 0; i < count; i++) {
    head = head->next;
  }
  return head;
}
