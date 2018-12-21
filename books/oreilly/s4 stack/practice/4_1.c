// 用栈判断式子{}, (), []是否平衡
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
