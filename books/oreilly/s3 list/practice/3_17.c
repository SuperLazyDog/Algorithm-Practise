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

// O(mn)
ListNode *getIntersectingNode(ListNode *head1, ListNode *head2) {
  ListNode *temp = head2;
  while (head1) {
    while (temp) {
      if (temp == head1) {
        return temp;
      }
      temp = temp->next;
    }
    temp = head2;
    head1 = head1->next;
  }
  return NULL;
}
