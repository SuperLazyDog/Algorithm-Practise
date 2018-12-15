// 双向链表
#include <stdio.h>
#include <stdlib.h>

struct doubleNode {
  int data;
  struct doubleNode *next;
  struct doubleNode *prev;
};

struct doubleNode *newDoubleNode(int data);
void deleteDoubleList(struct doubleNode **head);
void insert(struct doubleNode **head, int data, int position);
void delete(struct doubleNode **head, int position);
void showNode(struct doubleNode *head);

int main(int argc, char const *argv[]) {
  struct doubleNode *node = newDoubleNode(100);
  for (size_t i = 0; i < 9; i++) {
    insert(&node, i, 100);
  }
  showNode(node);
  puts("");
  delete(&node, 100);
  delete(&node, 9);
  delete(&node, 0);
  delete(&node, 4);
  showNode(node);
  deleteDoubleList(&node);
  return 0;
}

struct doubleNode *newDoubleNode(int data) {
  struct doubleNode *new = (struct doubleNode *)malloc(sizeof(struct doubleNode));
  new->prev = new->next = NULL;
  new->data = data;
  return new;
}

void deleteDoubleList(struct doubleNode **head) {
  struct doubleNode *temp, *temp2;
  temp = temp2 = *head;
  while (temp) {
    temp2 = temp->next;
    temp->prev = temp->next = NULL;
    free(temp);
    temp = temp2;
  }
  *head = NULL;
}

void insert(struct doubleNode **head, int data, int position) { // position从0开始
  struct doubleNode *temp, *temp2, *newNode;
  newNode = newDoubleNode(data);
  temp = temp2 = *head;
  int count = 0;
  if (!position) {
    newNode->prev = NULL;
    newNode->next = *head;
    *head = newNode;
    return;
  }
  while (count < position && temp) {
    count++;
    temp2 = temp;
    temp = temp->next;
  }
  if (!temp) {
    temp2->next = newNode;
    newNode->next = NULL;
    newNode->prev = temp2;
  } else {
    newNode->prev = temp2;
    newNode->next = temp;
    temp2->next = newNode;
    temp->prev = newNode;
  }
}

void delete(struct doubleNode **head, int position) {
  struct doubleNode *temp;
  int count = 0;
  temp = *head;
  if (position==0) {
    *head = temp->next;
    free(temp);
    if (*head) {
      (*head)->prev = NULL;
    }
    return;
  }
  while (count < position && temp) {
    count++;
    temp = temp->next;
  }
  if (temp) {
    temp->prev->next = temp->next;
    free(temp);
  }
}

void showNode(struct doubleNode *head) {
  struct doubleNode *temp = head;
  int i=0;
  while (temp) {
    printf("node[%d]: %d\n", i, temp->data);
    i++;
    temp = temp->next;
  }
}
