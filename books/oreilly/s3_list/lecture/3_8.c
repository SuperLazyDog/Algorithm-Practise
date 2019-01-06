// 循环链表
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

int main(int argc, char const *argv[]) {
  CircleNode *node;
  for (size_t i = 0; i < 10; i++) {
    insertAtBegin(&node, i);
  }
  deleteFirst(&node);
  deleteLast(&node);
  showNodes(node);
  delete(&node);
  return 0;
}

CircleNode *newCircleNode(int data) {
  CircleNode *new = (CircleNode *)malloc(sizeof(CircleNode));
  new->next = new;
  new->data = data;
  return new;
}

void delete(CircleNode **head) {
  CircleNode *temp = (*head)->next, *temp2;
  while (temp != *head) {
    temp2 = temp->next;
    free(temp);
    temp = temp2;
  }
  free(*head);
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
}
