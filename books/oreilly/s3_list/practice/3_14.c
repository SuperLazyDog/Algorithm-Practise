// 获取链表内循环长度
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

int roopLength(ListNode *head) {
  ListNode *slow, *fast;
  int fCount, sCount;
  fCount = sCount = 0;
  slow = fast = head;
  while (fast) {
    fast = fast->next;
    fCount++;
    if (!fast) {
      return 0;
    }
    if (fast == slow) {
      return fCount - sCount;
    }
    fast = fast->next;
    fCount++;
    if (fast == slow) {
      return fCount - sCount;
    }
    slow = slow->next;
    sCount++;
  }
  return 0;
}
