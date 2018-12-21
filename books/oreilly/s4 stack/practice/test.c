// 链表实现栈, push/pop都是开头处进行
// 1~题用
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

int isBalanced(char str[]) {
  int i = 0, temp;
  ListStack *head = createStack();
  while (str[i]) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') { // push
      push(&head, str[i]);
    } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') { // pop
      if (isEmptyStack(head)) {
        return 0;
      } else {
        temp = top(head);
        if ((str[i] == ')' && temp == '(') || (str[i] == ']' && temp == '[') || (str[i] == '}' && temp == '{')) {
          pop(&head);
        } else {
          return 0;
        }
      }
    }
    i++;
  }
  if (isEmptyStack(head)) {
    return 1;
  } else {
    return 0;
  }
}

double getPriority(char c) {
  switch (c) {
    case '+':
    case '-':
      return 1.;
    case '*':
    case '/':
      return 2.;
    case '(':
      return 3.;
    case ')':
      return 3.1;
    default:
      return -1.;
  }
}
// 对应+-*/ ()
void convertToSuffix(char str[]) {
  ListStack *stack = createStack();
  int i = 0, temp;
  printf("outputs: ");
  while (str[i]) {
    if (getPriority(str[i]) < 0) { // 字符是被运算单位
      // 直接输出
      printf("%c", str[i]);
    } else if (getPriority(str[i]) == 3.1) { // 字符是右括号
      // pop到左括号
      temp = pop(&stack);
      while (getPriority(temp) != 3.0) {
        printf("%c", temp);
        temp = pop(&stack);
      }
    } else { // t是左括号或者运算符
      // pop到左括号或者比优先级低的运算符
      temp = top(stack);
      int priority = getPriority(temp), priority2 = getPriority(str[i]);
      while (priority != 3 && priority2 <= priority) {
        printf("%c", pop(&stack));
        temp = top(stack);
        priority = getPriority(temp);
        priority2 = getPriority(str[i]);
      }
      // push
      push(&stack, str[i]);
    }
    i++;
  }
  while(!isEmptyStack(stack)) {
    printf("%c", pop(&stack));
  }
  puts("");
}

int caculateSuffix(char str[]) {
  ListStack *stack = createStack();
  int i = 0, priority, result;
  while (str[i]) {
    priority = getPriority(str[i]);
    if (priority < 0) { // 数字
      push(&stack, str[i]-'0');
    } else {
      int b = pop(&stack), a = pop(&stack);
      switch (str[i]) {
        case '+':
          push(&stack, a+b);
          break;
        case '-':
          push(&stack, a-b);
          break;
        case '*':
          push(&stack, a*b);
          break;
        case '/':
          push(&stack, a/b);
          break;
      }
    }
    i++;
  }
  result = pop(&stack);
  deleteStack(&stack);
  return result;
}

int caculateExpression(char str[]) {
  ListStack *operant = createStack(), *operator = createStack();
  for (int i = 0; str[i]; i++) {
    double priority = getPriority(str[i]);
    if (priority < 0) { // 数字
      push(&operant, str[i]-'0');
    } else if (priority == 3.1) { // 右括号
      char temp = pop(&operator);
      double sPriority = getPriority(temp);
      while (sPriority < 3) { // pop到左括号
        int b = pop(&operant), a = pop(&operant);
        switch (temp) {
          case '+':
            push(&operant, a + b);
            break;
          case '-':
            push(&operant, a - b);
            break;
          case '*':
            push(&operant, a * b);
            break;
          case '/':
            push(&operant, a / b);
            break;
        }
        temp = pop(&operator);
        sPriority = getPriority(temp);
      }
    } else if (priority == 3) { // 左括号
      push(&operator, str[i]);
    } else { // 运算符
      // 计算所有优先度大于等于当前运算符的
      // puts("运算符");
      if (!isEmptyStack(operator)) {
        char temp = top(operator);
        double sPriority = getPriority(temp);
        while (sPriority >= priority && sPriority != 3) {
          temp = pop(&operator);
          int b = pop(&operant), a = pop(&operant);
          switch (temp) {
            case '+':
              push(&operant, a + b);
              break;
            case '-':
              push(&operant, a - b);
              break;
            case '*':
              push(&operant, a * b);
              break;
            case '/':
              push(&operant, a / b);
              break;
          }
          temp = top(operator);
          sPriority = getPriority(temp);
        }
      }
      push(&operator, str[i]);
    }
  }
  while (!isEmptyStack(operator)) {
    char temp = pop(&operator);
    int b = pop(&operant), a = pop(&operant);
    switch (temp) {
      case '+':
        push(&operant, a + b);
        break;
      case '-':
        push(&operant, a - b);
        break;
      case '*':
        push(&operant, a * b);
        break;
      case '/':
        push(&operant, a / b);
        break;
    }
  }
  int result = top(operant);
  deleteStack(&operant);
  deleteStack(&operator);
  return result;
}

int main(int argc, char const *argv[]) {
  // printf("isBalanced: %d\n", isBalanced("(1+2*(3)-[12312ghv+sa/{1*2}])*{3+[5-(6*6)]}"));

  // char s[128];
  // do {
  //   printf("inputs: ");
  //   scanf("%s", s);
  //   convertToSuffix(s);
  //   // printf("suffix: ");
  //   scanf("%s", s);
  //   printf("result: %d\n", caculateSuffix(s));
  //   puts("");
  // } while(strcmp("quit", s));

  char s[128];
  do {
    printf("inputs: ");
    scanf("%s", s);
    printf("result: %d\n", caculateExpression(s));
    puts("");
  } while(strcmp("quit", s));
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
