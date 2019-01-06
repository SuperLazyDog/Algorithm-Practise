// 链表实现栈, push/pop都是开头处进行
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct listStack {
  int data;
  struct listStack *next;
} ListStack;
ListStack *createStack();
void deleteStack(ListStack **head);
void push(ListStack **head, int data);
int pop(ListStack **head);
int top(ListStack *head);
int isEmptyStack(ListStack *head);
void showStack(ListStack *head);
void showStack2(ListStack *head);

int main(int argc, char const *argv[]) {
  ListStack *head = NULL;
  for (int i = 0; i < 10; i++) {
    push(&head, i);
  }
  showStack(head);
  pop(&head);
  pop(&head);
  push(&head, rand()%100);
  push(&head, rand()%100);
  showStack(head);
  return 0;
}

ListStack *createStack() {
  return NULL;
}

void deleteStack(ListStack **head) {
  ListStack *temp = *head, *temp2;
  while (temp) {
    temp2 = temp->next;
    free(temp);
    temp = temp2;
  }
  *head = NULL;
}

void push(ListStack **head, int data) {
  ListStack *new = (ListStack *)malloc(sizeof(ListStack));
  new->data = data;
  new->next = *head;
  *head = new;
}

int pop(ListStack **head) {
  ListStack *top = *head;
  if (top) {
    int data = top->data;
    *head = top->next;
    free(top);
    return data;
  }
  return INT_MIN;
}

int top(ListStack *head) {
  if (head) {
    return head->data;
  }
  return INT_MIN;
}

int isEmptyStack(ListStack *head) {
  return head == NULL;
}

void showStackHelper(ListStack *head, int count) {
  if (!head) {
    return;
  }
  showStackHelper(head->next, count + 1);
  printf("stack[%d]: %d\n", count, head->data);
}

void showStack(ListStack *head) {
  showStackHelper(head, 0);
  puts("");puts("");
}

void showStack2(ListStack *head) {
  ListStack *temp = head;
  int i = 0;
  while (temp) {
    printf("stack[%d]: %d\n", i, temp->data);
    i++;
    temp = temp->next;
  }
  puts("");puts("");
}
