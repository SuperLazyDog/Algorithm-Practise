// 反向打印链表
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

void printListFromEnd(ListNode *head) {
  if (!head) {
    puts("");puts("");
    return;
  } else {
    printListFromEnd(head->next);
    printf("data: %d\n", head->data);
  }
}
