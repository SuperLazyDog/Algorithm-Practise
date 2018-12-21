// 一次遍历计算中缀表达式
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
    } else { // 运算符或者左括号
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
