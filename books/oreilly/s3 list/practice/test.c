// 单向链表
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

ListNode *getCircleStartPoint(ListNode *head, ListNode *fast) {
  ListNode *slow = head, *temp = fast;
  while (temp != slow) {
    slow = slow->next;
    temp = temp->next;
  }
  return slow;
}

int getListType(ListNode *head) {
  // 0: 线性  1: 循环
  ListNode *slow, *fast;
  slow = fast = head;
  while (slow && fast) {
    fast = fast->next;
    if (fast == slow) {
      printf("%d\n", getCircleStartPoint(head, fast)->data);
      return 1;
    }
    if (!fast) {
      return 0;
    }
    fast = fast->next;
    if (fast == slow) {
      printf("%d\n", getCircleStartPoint(head, fast)->data);
      return 1;
    }
    slow = slow->next;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  ListNode *p = createList(0);
  for (int i = 1; i < 10; i++) {
    addElement(&p, i, 5);
  }
  listLength(p);
  puts("");puts("");
  printf("%s\n", getListType(p) == 0 ? "线性":"循环");
  p->next->next->next = p->next->next;
  printf("%s\n", getListType(p) == 0 ? "线性":"循环");
  // deleteList(&p);
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
