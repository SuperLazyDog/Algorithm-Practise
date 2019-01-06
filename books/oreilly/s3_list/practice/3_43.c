// 把链表按数据奇偶分,并使偶数的靠前
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
void addElementAtLast(ListNode **head, int data) {
  ListNode *temp = *head, *temp2, *newNode = createList(data);
  if (!*head) {
    *head = newNode;
    return;
  }
  while (temp) {
    temp2 = temp;
    temp = temp->next;
  }
  temp2->next = newNode;
}

void SplitWithEven(ListNode **head) {
  ListNode *even=NULL, *odd=NULL, *temp = *head, *temp2;
  if (!*head) {
    return;
  }
  while (temp) {
    if (temp->data % 2) { // 奇
      addElementAtLast(&odd, temp->data);
    } else { // 偶
      addElementAtLast(&even, temp->data);
    }
    temp = temp->next;
  }
  temp = *head;
  deleteList(&temp);
  temp = even;
  while (temp) {
    temp2 = temp;
    temp = temp->next;
  }
  temp2->next = odd;
  *head = even;
}
