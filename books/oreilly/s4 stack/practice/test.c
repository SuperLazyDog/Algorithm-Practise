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
    if (priority == -1) {
      push(&stack, str[i]-'0');
    } else {
      int b = pop(&stack), a = pop(&stack);
      switch (str[i]) {
        case '+':
          push(&stack, a + b);
          break;
        case '-':
          push(&stack, a - b);
          break;
        case '*':
          push(&stack, a * b);
          break;
        case '/':
          push(&stack, a / b);
          break;
      }
    }
    i++;
  }
  result = pop(&stack);
  deleteStack(&stack);
  return result;
}

int caculate(int a, int b, char c) {
  switch (c) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      return -1;
  }
}

int caculateExpression(char str[]) {
  ListStack *operants = createStack(), *operators = createStack();
  int i = 0, result;
  while (str[i]) {
    double priority = getPriority(str[i]);
    if (priority < 0) { // 数字
      push(&operants, str[i]-'0');
    } else if (priority == 3.1) { // )
      // 把 ( 前的全都算掉, 删除遇到的第一个 (
      char temp = pop(&operators);
      int sPriority = getPriority(temp);
      while (sPriority != 3.0) {
        int b = pop(&operants), a = pop(&operants);
        push(&operants, caculate(a, b, temp));
        temp = pop(&operators);
        sPriority = getPriority(temp);
      }
    } else { // +-*/ (
      // 把 回溯到最开始或 ( 之间比当前符号优先度高或相等的算完
      char temp = top(operators);
      int sPriority = getPriority(temp);
      while (!isEmptyStack(operators) && sPriority != 3.0 && sPriority >= priority) {
        int b = pop(&operants), a = pop(&operants);
        push(&operants, caculate(a, b, temp));
        temp = top(operators);
        sPriority = getPriority(temp);
      }
      push(&operators, str[i]);
    }
    i++;
  }
  while (!isEmptyStack(operators)) {
    int b = pop(&operants), a = pop(&operants);
    push(&operants, caculate(a, b, pop(&operators)));
  }
  result = pop(&operants);
  deleteStack(&operants);
  deleteStack(&operators);
  return result;
}

int main(int argc, char const *argv[]) {
  // printf("isBalanced: %d\n", isBalanced("(1+2*(3)-[12312ghv+sa/{1*2}])*{3+[5-(6*6)]}"));

  char s[128], ss[128];
  do {
    printf("inputs: ");
    scanf("%s", s);
    convertToSuffix(s);
    printf("suffix: ");
    scanf("%s", ss);
    printf("result: %d\n", caculateSuffix(ss));
    printf("不转换为后缀表达式的result: %d\n", caculateExpression(s));
    puts("");
  } while(strcmp("quit", s));

  // char s[128];
  // do {
  //   printf("inputs: ");
  //   scanf("%s", s);
  //   printf("result: %d\n", caculateExpression(s));
  //   puts("");
  // } while(strcmp("quit", s));
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
