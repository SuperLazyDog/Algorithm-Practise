// 将单向链表倒置
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

// TODO p69 理解递归版
void reverseList(ListNode **head) {
  ListNode *temp, *temp2;
  temp2 = NULL;
  while (*head) {
    temp = (*head)->next;
    (*head)->next = temp2;
    temp2 = *head;
    (*head) = temp;
  }
  *head = temp2;
}
