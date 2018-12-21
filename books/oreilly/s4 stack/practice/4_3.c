// 计算后缀表达式
// typedef struct listStack {
//   int data;
//   struct listStack *next;
// } ListStack;
// ListStack *createStack();
// void deleteStack(ListStack **head);
// void push(ListStack **head, int data);
// int pop(ListStack **head);
// int top(ListStack *head);
// int isEmptyStack(ListStack *head);
// void showStack(ListStack *head);
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

int caculateSuffix(char str[]) {
  ListStack *stack = createStack();
  int i = 0, priority, result;
  while (str[i]) {
    priority = getPriority(str[i]);
    if (priority < 0) { // 数字
      push(&stack, atoi(str[i]));
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
