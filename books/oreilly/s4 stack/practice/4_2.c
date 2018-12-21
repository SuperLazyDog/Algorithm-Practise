// 中缀表达法转换为后缀表达法
// A+B => AB+
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
  deleteStack(&stack);
}
