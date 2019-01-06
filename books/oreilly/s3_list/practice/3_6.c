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
  ListNode *current, *temp;
  int currentCount, tempCount;
  currentCount = tempCount = 0;
  current = temp = head;
  while (current) {
    current = current->next;
    currentCount++;
    // 确认新节点是否与现有节点中的某个一致
    temp = head;
    tempCount = 0;
    while (temp != current) {
      temp = temp->next;
      tempCount++;
    }
    if (tempCount < currentCount) {
      return 1;
    }
  }
  return 0;
}
