// 复制链表
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

// TODO: 哈希表以后再做
// ListNode *clone(ListNode *head) {
//   ListNode *newHead = NULL, *temp = head;
//   int count = 0, i = 0;
//   if (!head) {
//     return NULL;
//   }
//   while (temp) {
//     count++;
//     temp = temp->next;
//   }
//   ListNode newNodes[count], *newNode;
//   temp = head;
//   while (temp) {
//     newNode = createList(temp->data);
//     newNodes[i] = newNode;
//     i++;
//     temp = temp->next;
//   }
//   for (i = 0; i < count-1; i++) {
//     newNodes[i]->next = newNodes[i+1];
//   }
//   newNodes[count-1]->next = NULL;
//   temp = newNodes[0];
//   newNodes = {};
//   return temp;
// }
