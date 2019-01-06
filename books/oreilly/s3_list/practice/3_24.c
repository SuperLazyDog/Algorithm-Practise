// 寻找单向链表的中间点
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

// O(n)
// 长度为n, 中间点为第 n/2+n%2 个, 以0开始的索引为(n-1)/2
ListNode *getMiddleNode(ListNode *head) {
  ListNode *temp = head;
  int count = 0;
  while (temp) {
    count++;
    temp = temp->next;
  }
  count = count/2 + count%2;
  temp = head;
  for (size_t i = 1; i < count; i++) {
    temp = temp->next;
  }
  return temp;
}
