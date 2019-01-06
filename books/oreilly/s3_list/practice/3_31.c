// 合并已经排序好的两个单向链表 升序
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

ListNode *mergeList(ListNode *a, ListNode *b) {
  ListNode *result = NULL;
  if (!a) {
    return b;
  }
  if (!b) {
    return a;
  }
  if (a->data < b->data) {
    result = a;
    result->next = mergeList(a->next, b);
  } else {
    result = b;
    result->next = mergeList(b->next, a);
  }
  return result;
}
