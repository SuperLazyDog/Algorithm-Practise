// 单向链表
// 17~23题用
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

ListNode *getIntersectingNode(ListNode *head1, ListNode *head2) {
  int l1, l2, d;
  ListNode *temp1 = head1, *temp2 = head2;
  l1 = l2 = 0;
  while (temp1) {
    l1++;
    temp1 = temp1->next;
  }
  while(temp2) {
    l2++;
    temp2 = temp2->next;
  }
  d = l1 - l2;
  if (d > 0) {
    for (size_t i = 0; i < d; i++) {
      head1 = head1->next;
    }
  } else {
    d = -d;
    for (size_t i = 0; i < d; i++) {
      head2 = head2->next;
    }
  }
  while (head1 != head2) {
    head1 = head1->next;
    head2 = head2->next;
  }
  return head1;
}

int main(int argc, char const *argv[]) {
  ListNode *p = createList(-50), *q = createList(-100), *temp;
  for (int i = 1; i < 10; i++) {
    addElement(&p, rand()%10, 0);
    addElement(&q, rand()%10, 0);
  }
  listLength(p);
  puts("");puts("");
  listLength(q);
  p->next->next->next = q->next;
  temp = getIntersectingNode(p, q);
  // puts("");puts("");
  // listLength(p);
  // puts("");puts("");
  // listLength(q);
  if (!temp) {
    puts("两条链表独立");
  } else {
    printf("两条链表合并, 合并处数据: %d\n", temp->data);
  }
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
  return count;
}

void addElement(ListNode **head, int data, int position) {
  ListNode *new = (ListNode *)malloc(sizeof(ListNode)), *temp, *temp2;
  int count = 0;
  new->data = data;
  new->next = NULL;
  if (position == 0) { // 插入最前方
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
