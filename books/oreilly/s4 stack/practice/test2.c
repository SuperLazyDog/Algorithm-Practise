// 链表实现栈, push/pop都是开头处进行
// 5,6, 8~题用
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

ListStack *getMinStack(ListStack *head) {
  ListStack *new = createStack(), *temp = head, *temp2 = NULL, *temp3 = NULL;
  int isFirst = 1, min;
  // 把head全部倒置
  while (temp) {
    temp3 = temp->next;
    temp->next = temp2;
    temp2 = temp;
    temp = temp3;
  }
  temp = temp2;
  // 创建 minStack
  while (temp) {
    if (isFirst) {
      isFirst = 0;
      min = temp->data;
    } else {
      if (min > temp->data) {
        min = temp->data;
      }
    }
    push(&new, min);
    temp = temp->next;
  }
  // 把temp再次倒置，回到初始状态
  temp = temp2;
  temp2 = NULL;
  while (temp) {
    temp3 = temp->next;
    temp->next = temp2;
    temp2 = temp;
    temp = temp3;
  }
  return new;
}

ListStack *getAdvancedMinStack(ListStack *head) {
  ListStack *new = createStack(), *temp = head, *temp2 = NULL, *temp3 = NULL;
  int isFirst = 1, min;
  if (!head) {
    deleteStack(&new);
    return NULL;
  }
  // 反转head
  while (temp) {
    temp3 = temp->next;
    temp->next = temp2;
    temp2 = temp;
    temp = temp3;
  }
  temp = temp2; // 原stack末尾
  // 生成minStack
  while (temp) {
    if (isFirst) {
      min = temp->data;
      push(&new, min);
      isFirst = 0;
    } else {
      if (min >= temp->data) {
        min = temp->data;
        push(&new, min);
      }
    }
    temp = temp->next;
  }
  // 再次反转head, 回到原样
  temp = temp2;
  temp2 = NULL;
  while (temp) {
    temp3 = temp->next;
    temp->next = temp2;
    temp2 = temp;
    temp = temp3;
  }
  return new;
}

int isPalindrome(char str[]) {
  int i = 0, j = 0;
  while (str[j]) {
    j++;
  }
  j = j - 1;
  while (i <= j && str[i] == str[j]) {
    i++;
    j--;
  }
  return i <= j ? 0 : 1;
}

int main(int argc, char const *argv[]) {
  // ListStack *head = NULL, *temp = NULL;
  // push(&head, 2);
  // push(&head, 6);
  // push(&head, 4);
  // push(&head, 1);
  // push(&head, 5);
  // push(&head, 1);
  // temp = getAdvancedMinStack(head);
  // showStack(head);
  // showStack(temp);
  // deleteStack(&head);
  // deleteStack(&temp);


  // char str[128];
  // do {
  //   printf("str: ");
  //   scanf("%s", str);
  //   printf("isPalindrome: %d\n", isPalindrome(str));
  // } while(strcmp(str, "quit"));
  int a[10];
  for (int i = 0; i < 11; i++) {
    a[i] = i;
  }
  // for (int i = 0; i < 10; i++) {
  //   printf("%d\n", a[i]);
  // }
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
