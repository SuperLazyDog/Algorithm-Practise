// 获取链表倒数第n个元素
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

ListNode *getNodeFromLastAt(ListNode *head, int position) {
  ListNode *temp1, *temp2;
  int count;
  temp1 = temp2 = head;
  for (int i = 0; i < position; i++) {
    if (temp2) {
      temp2 = temp2->next;
    } else {
      puts("链表长度不够");
      return NULL;
    }
  }
  while (temp2) {
    temp2 = temp2->next;
    temp1 = temp1->next;
  }
  return temp1;
}
