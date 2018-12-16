// 将元素插入排序好的链表, 从小到大
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

void insertInSortedList(ListNode **head, int data) {
  // 相等的新插入的在前面
  ListNode *newNode = createList(data), *temp,  *temp2;
  temp = temp2 = *head;
  if (!*head || data <= (*head)->data) { // 链表为空或插入在第一个
    newNode->next = *head;
    *head = newNode;
    return;
  }
  while (temp && data > temp->data) {
    temp2 = temp;
    temp = temp->next;
  }
  newNode->next = temp;
  temp2->next = newNode;
}
