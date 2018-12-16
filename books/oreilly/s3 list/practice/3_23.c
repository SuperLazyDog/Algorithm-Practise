// 寻找两个单向链表的合并点
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

// O(max(m, n))
ListNode *getIntersectingNode(ListNode *head1, ListNode *head2) {
  int l1, l2, d;
  ListNode *temp1 = head1, *temp2 = head2;
  l1 = l2 = 0;
  while (temp1) {
    l1++;
    temp1 = temp1->next;
  }
  while(temp2) {
    l2++;
    temp2 = temp2->next;
  }
  d = l1 - l2;
  if (d > 0) {
    for (size_t i = 0; i < d; i++) {
      head1 = head1->next;
    }
  } else {
    d = -d;
    for (size_t i = 0; i < d; i++) {
      head2 = head2->next;
    }
  }
  while (head1 != head2) {
    head1 = head1->next;
    head2 = head2->next;
  }
  return head1;
}
