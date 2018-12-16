// 单向链表
// 24~31题用
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
  return NULL;
}

void printListFromEnd(ListNode *head) {
  if (!head) {
    puts("");puts("");
    return;
  } else {
    printListFromEnd(head->next);
    printf("data: %d\n", head->data);
  }
}

void insertInSortedList(ListNode **head, int data) {
  // 相等的插入在相等元素前
  ListNode *newNode = createList(data), *temp = *head, *temp2 = *head;
  if (!*head || data <= (*head)->data) {
    newNode->next = *head;
    *head = newNode;
    return;
  }
  while (temp && data > temp->data) {
    temp2 = temp;
    temp = temp->next;
  }
  temp2->next = newNode;
  newNode->next = temp;
}

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

int main(int argc, char const *argv[]) {
  ListNode *p = NULL, *q = NULL;
  for (int i = 0; i < 10; i++) {
    insertInSortedList(&p, rand()%100);
    insertInSortedList(&q, rand()%100);
  }
  // printf("%d\n", getMiddleNode(p)->data);
  listLength(p);
  listLength(q);
  listLength(mergeList(p, q));
  deleteList(&p);
  deleteList(&q);
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
