// 单向链表
// 1~16题用
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

int getListType(ListNode *head) {
  // 0: 线性  1: 循环
  ListNode *slow, *fast;
  slow = fast = head;
  while (slow && fast) {
    fast = fast->next;
    if (fast == slow) {
      printf("循环起点: %d\n", getCircleStartPoint(head, fast)->data);
      printf("循环长度: %d\n", roopLength(head));
      return 1;
    }
    if (!fast) {
      return 0;
    }
    fast = fast->next;
    if (fast == slow) {
      printf("循环起点: %d\n", getCircleStartPoint(head, fast)->data);
      printf("循环长度: %d\n", roopLength(head));
      return 1;
    }
    slow = slow->next;
  }
  return 0;
}

void insertInSortedList(ListNode **head, int data) {
  // 相等的新插入的在前面
  ListNode *newNode = createList(data), *temp,  *temp2;
  temp = temp2 = *head;
  if (!*head || data <= (*head)->data) { // 链表为空或插入在第一个
    newNode->next = *head;
    *head = newNode;
    return;
  }
  while (temp && data > temp->data) {
    temp2 = temp;
    temp = temp->next;
  }
  newNode->next = temp;
  temp2->next = newNode;
}

void reverseList(ListNode **head) {
  ListNode *temp, *temp2;
  temp2 = NULL;
  while (*head) {
    temp = (*head)->next;
    (*head)->next = temp2;
    temp2 = *head;
    (*head) = temp;
  }
  *head = temp2;
}

int main(int argc, char const *argv[]) {
  ListNode *p = createList(0);
  for (int i = 1; i < 20; i++) {
    // addElement(&p, i, 5);
    insertInSortedList(&p, rand()%100);
  }
  listLength(p);
  puts("");puts("");
  reverseList(&p);
  listLength(p);
  // puts("");puts("");
  // printf("%s\n", getListType(p) == 0 ? "线性":"循环");
  // p->next->next = p->next;
  // printf("%s\n", getListType(p) == 0 ? "线性":"循环");
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
