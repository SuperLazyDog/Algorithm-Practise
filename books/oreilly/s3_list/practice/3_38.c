// 倒置链表的前k个元素
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

void reverseFirstKNodes(ListNode **head, int k) {
  int count = 0;
  if (!head) {
    return;
  }
  ListNode *temp = *head, *temp2 = *head, *temp3, *next = NULL;
  while (temp && count < k) {
    count++;
    temp = temp->next;
  }
  if (count < k) { // 数量不足k, 比如空链表
    return;
  }
  // 反转temp2到temp内所有元素
  while (temp2 != temp) {
    temp3 = temp2->next;
    temp2->next = next;
    next = temp2;
    temp2 = temp3;
  }
  temp2 = next; // 新开头
  (*head)->next = temp;
  *head = temp2;
}
