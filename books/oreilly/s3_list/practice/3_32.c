// 对单向链表元素两两置换 A B C D E -> B A D C E
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
void swapListEle(ListNode **head) {
  ListNode *a = *head, *b, *c, *d = NULL;
  while (a && a->next) {
    b = a;
    c = a->next;
    a = c->next;
    b->next = c->next;
    c->next = b;
    if (d) {
      d->next = c;
    } else {
      *head = c;
    }
    d = b;
  }
}

// 递归版
void swapListEle(ListNode **head, ListNode *before) {
  ListNode *a = *head, *b, *c;
  if (!a || !(a->next)) {
    return;
  }
  b = a;
  c = b->next;
  b->next = c->next;
  c->next = b;
  if (before) {
    before->next = c;
  } else {
    *head = c;
  }
  swapListEle(&b->next, b);
}
