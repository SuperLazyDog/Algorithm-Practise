// 单向链表
// 32~题用
#include <stdio.h>
#include <stdlib.h>

struct listNode {
  int data;
  struct listNode *next;
};
typedef struct listNode ListNode;

int listLength(ListNode *head); // 遍历
void addElement(ListNode **head, int data, int position); // position从0开始
void deleteElement(ListNode **head, int position);
ListNode *createList(int data);
void deleteList(ListNode **p);

// void swapListEle(ListNode **head) {
//   ListNode *a = *head, *b, *c, *d = NULL;
//   while (a && a->next) {
//     b = a;
//     c = a->next;
//     a = c->next;
//     b->next = c->next;
//     c->next = b;
//     if (d) {
//       d->next = c;
//     } else {
//       *head = c;
//     }
//     d = b;
//   }
// }
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

int main(int argc, char const *argv[]) {
  ListNode *p = NULL;
  for (int i = 0; i < 11; i++) {
    addElement(&p, i, 100);
  }
  listLength(p);
  swapListEle(&p, NULL);
  listLength(p);
  deleteList(&p);
  return 0;
}

int listLength(ListNode *head) {
  int count = 0;
  while (head) { // 遍历的话在这里加入遍历内容
    printf("data[%d]: %d\n", count, head->data);
    count++;
    head = head->next;
  }
  puts("");puts("");
  return count;
}

void addElement(ListNode **head, int data, int position) {
  ListNode *new = (ListNode *)malloc(sizeof(ListNode)), *temp, *temp2;
  int count = 0;
  new->data = data;
  new->next = NULL;
  if (position == 0 || !*head) { // 插入最前方
    new->next = *head;
    *head = new;
  } else {
    temp = temp2 = *head;
    while (temp && count < position) {
      count++;
      temp2 = temp;
      temp = temp->next;
    }
    temp2->next = new;
    new->next = temp;
  }
}

void deleteElement(ListNode **head, int position) {
  ListNode *temp = *head, *temp2 = *head;
  int i = 0;
  if (!*head) { // 链表没有元素
    return;
  }
  if (position == 0) {
    *head = (*head)->next;
    free(temp);
  } else {
    while (temp && i < position) {
      temp2 = temp;
      temp = temp->next;
      i++;
    }
    if (temp) {
      temp2->next = temp->next;
      free(temp);
    }
  }
}

ListNode *createList(int data) {
  ListNode *p = (ListNode *)malloc(sizeof(ListNode));
  p->data = data;
  p->next = NULL;
  return p;
}

void deleteList(ListNode **p) {
  ListNode *temp = *p, *temp2;
  while (temp) {
    temp2 = temp->next;
    free(temp);
    temp = temp2;
  }
  *p = NULL;
}
