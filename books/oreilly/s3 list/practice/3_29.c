// 判断链表长度奇数偶数
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

// TODO: 书上方法或许更好 p74
int isListLengthEven(ListNode *head) {
  int count = 0;
  while (head) {
    count++;
    head = head->next;
  }
  return 1 - head % 2
}
