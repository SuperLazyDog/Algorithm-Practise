#include <stdio.h>
#include <stdlib.h>

// 連結リストを使ってスタックを実装せよ
struct listNode {
  int data;
  struct listNode *next;
};

struct stack {
  struct listNode *head;
};

struct stack *createStack() {
  struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
  if (stack == NULL) {
    printf("error\n");
    return NULL;
  }
  stack->head = NULL;
  return stack;
}

void push(struct stack *stack, int data) {
  if (stack == NULL) {
    stack = createStack();
    if (stack == NULL) {
      puts("error");
      return;
    }
  }
  if (stack->head == NULL) {
    stack->head = (struct listNode *)malloc(sizeof(struct listNode));
    stack->head->next = NULL;
    stack->head->data = data;
  } else {
    struct listNode *temp = stack->head, *new;
    new = (struct listNode *)malloc(sizeof(struct listNode));
    new->next = stack->head;
    new->data = data;
    stack->head = new;
  }
}

int pop(struct stack *stack) {
  if (stack == NULL) {
    return -1;
  }
  struct listNode *temp = stack->head;
  if (temp == NULL) {
    return -1;
  }
  stack->head = temp->next;
  int result = temp->data;
  free(temp);
  return result;
}

void deleteStack(struct stack *stack) {
  if (stack==NULL) {
    return;
  }
  struct listNode *temp;
  while (stack->head != NULL) {
    temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
  }
  free(stack);
}

void showStack(struct stack *stack) {
  if (stack == NULL) {
    printf("error\n");
    return;
  }
  if (stack->head == NULL) {
    puts("no data");
    return;
  }
  struct listNode *temp = stack->head;
  int i=0;
  while (temp != NULL) {
    printf("stack[%d]: %d\n", i++, temp->data);
    temp = temp->next;
  }
}


int main() {
  int a[8];
  struct stack *stack =createStack();

  for (int i = 0; i < 8; i++) {
    push(stack, i);
  }
  pop(stack);pop(stack);
  showStack(stack);
  deleteStack(stack);

  return 0;
}
