// 循环链表
// 36, 40题用
#include <stdio.h>
#include <stdlib.h>

typedef struct circleNode {
  int data;
  struct circleNode *next;
} CircleNode;
CircleNode *newCircleNode(int data);
void delete(CircleNode **head);
void insertAtEnd(CircleNode **head, int data);
void insertAtBegin(CircleNode **head, int data);
void deleteFirst(CircleNode **head);
void deleteLast(CircleNode **head);
void showNodes(CircleNode *head);

void splitList(CircleNode *head, CircleNode **r) {
  CircleNode *slow, *fast; // fast应为最后一个, slow为前一半最后一个
  slow = fast = head;
  if (!head) {
    return;
  }
  while (fast->next != head && fast->next->next != head) {
    fast = fast->next->next;
    slow = slow->next;
  }
  if (fast->next->next == head) { // 有奇数个
    fast = fast->next;
  }
  *r = slow->next;
  slow->next = head;
  fast->next = *r;
}

int getJosephuPosition(int n, int m) {
  CircleNode *head = newCircleNode(0), *temp = head, *temp2;
  for (int i = 1; i < n; i++) {
    insertAtEnd(&head, i);
  }
  showNodes(head);
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < m - 2; j++) {
      temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    temp2->next = temp2;
    delete(&temp2);
  }
  showNodes(temp);
  // delete(&temp);
  return temp->data;
}

int main(int argc, char const *argv[]) {
  // CircleNode *node, *m;
  // for (size_t i = 0; i < 10; i++) {
  //   insertAtEnd(&node, i);
  // }
  // // showNodes(node);
  // splitList(node, &m);
  // showNodes(node);
  // showNodes(m);
  // delete(&node);
  // delete(&m);

  getJosephuPosition(40, 18);
  return 0;
}

CircleNode *newCircleNode(int data) {
  CircleNode *new = (CircleNode *)malloc(sizeof(CircleNode));
  new->next = new;
  new->data = data;
  return new;
}

void delete(CircleNode **head) {
  CircleNode *temp, *temp2;
  if (!*head) {
    return;
  }
  temp = (*head)->next;
  while (temp != *head) {
    temp2 = temp->next;
    free(temp);
    temp = temp2;
  }
  free(temp);
  *head = NULL;
}

void insertAtEnd(CircleNode **head, int data) {
  CircleNode *temp, *temp2, *new = newCircleNode(data);
  temp = temp2 = *head;
  if (!(*head)) {
    *head = new;
    return;
  }
  do {
    temp2 = temp;
    temp = temp->next;
  } while(temp != *head);
  temp2->next = new;
  new->next = temp;
}

void insertAtBegin(CircleNode **head, int data) {
  // 先插入到最后，再把开头移到最后
  // CircleNode *temp;
  // insertAtEnd(head, data);
  // temp = *head;
  // while (temp->next != *head) {
  //   temp = temp->next;
  // }
  // *head = temp;

  // 常规操作
  CircleNode *temp, *new;
  new = newCircleNode(data);
  if (*head) {
    temp = *head;
    while (temp->next != *head) {
      temp = temp->next;
    }
    temp->next = new;
    new->next = *head;
  }
  *head = new;
}

void deleteFirst(CircleNode **head) {
  CircleNode *temp = *head;
  if (!*head) {
    return;
  }
  while (temp->next != *head) {
    temp = temp->next;
  }
  temp->next = (*head)->next;
  free(*head);
  *head = temp->next;
}

void deleteLast(CircleNode **head) {
  CircleNode *temp, *temp2;
  temp = temp2 = *head;
  if (!*head) {
    return;
  }
  while (temp->next != *head) {
    temp2 = temp;
    temp = temp->next;
  }
  temp2->next = *head;
  free(temp);
}

void showNodes(CircleNode *head) {
  CircleNode *temp = head;
  int count = 0;
  do {
    printf("node[%d]: %d\n", count, temp->data);
    temp = temp->next;
    count++;
  } while(temp != head);
  printf("count: %d\n", count);
  puts("");
}
