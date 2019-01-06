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
ListNode *getMiddleNode(ListNode *head) {
  ListNode *slow, *fast;
  slow = fast = head;
  while (fast) {
    fast = fast->next;
    if (!fast) {
      return slow;
    }
    fast = fast->next;
    if (!fast) {
      return slow;
    } else {
      slow = slow->next;
    }
  }
}
