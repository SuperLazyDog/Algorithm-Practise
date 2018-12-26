// 链表实现栈, push/pop都是开头处进行
// 9直接在4_9.c
// 5,6, 8, 10题用
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

// int isPalindrome(char str[]) {
//   int i = 0, j = 0;
//   while (str[j]) {
//     j++;
//   }
//   j = j - 1;
//   while (i <= j && str[i] == str[j]) {
//     i++;
//     j--;
//   }
//   return i <= j ? 0 : 1;
// }
int isPalindrome(char str[]) {
  int i = 0, j = 0;
  ListStack *s = createStack();
  if (!str) {
    return 0;
  }
  while (str[j]) { // 有效为 2k+1, 此处跳出循环则长度为2k
    j++;
    if (!str[j]) { // 跳过为 2k+2, 此处跳出循环则长度为2k+1
      // 不用push, 此时元素是正中间的, 比较的时候用不上
      i++; // 跳过正中间
      break;
    }
    push(&s, str[i]);
    i++;
    j++;
  }
  while (str[i] && str[i] == pop(&s)) {
    i++;
  }
  deleteStack(&s);
  if (!str[i]) {
    return 1;
  } else {
    return 0;
  }
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


  char str[128];
  do {
    printf("str: ");
    scanf("%s", str);
    printf("isPalindrome: %d\n", isPalindrome(str));
  } while(strcmp(str, "quit"));
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
