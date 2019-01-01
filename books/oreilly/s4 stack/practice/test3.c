// 链表实现栈, push/pop都是开头处进行
// 14, 15在各自文件里
// 11, 20题用
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

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

// void insertAtBottom(ListStack **s, int data) {
//   int temp;
//   if (!*s) {
//     push(s, data);
//     return;
//   }
//   temp = pop(s);
//   insertAtBottom(s, temp);
//   push(s, data);
// }
//
// void reverse(ListStack **s) {
//   if (!s || !*s) { // stack为空
//     return;
//   }
//   int data = pop(s);
//   reverse(s);
//   // 插入到最后
//   insertAtBottom(s, data);
// }
void reverse(ListStack **s) {
  ListStack *new = createStack();
  while (*s) {
    push(&new, pop(s));
  }
  while (new) {
    ListStack *temp2 = new, *temp3 = new;
    while (temp2->next) {
      temp3 = temp2;
      temp2 = temp2->next;
    }
    if (temp2 == temp3) { // 只剩一个元素
      new = NULL;
      temp3 = NULL;
    } else {
      temp3->next = NULL;
    }
    push(s, temp2->data);
    free(temp2);
  }
}

int canDo(char str[]) {
  int length = 0;
  for (int i = 0; str[i]; i++) {
    if (str[i] == 'S') {
      length++;
    } else if (str[i] == 'X') {
      length--;
      if (length < 0) {
        return 0;
      }
    }
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  // ListStack *head = NULL;
  // for (int i = 0; i < 10; i++) {
  //   push(&head, i);
  // }
  // showStack2(head);
  // reverse(&head);
  // showStack2(head);
  char str[128];
  do {
    printf("str: ");
    scanf("%s", str);
    printf("cando: %d\n", canDo(str));
  } while(strcmp(str, "q"));
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
