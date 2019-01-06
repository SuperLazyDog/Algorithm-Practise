// 生成span, 优化版 O(n^2) -> O(n)
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

// TODO: Review [理解此题栈的用法]
int *getSpans(int a[], int n) {
  ListStack *s = createStack();
  int *result = (int *)malloc(sizeof(int)*n);
  int p;
  for (int i = 0; i < n; i++) {
    while (!isEmptyStack(s)) {
      if (a[i] > a[top(s)]) {
        pop(&s);
      } else {
        break;
      }
    }
    if (isEmptyStack(s)) {
      p = -1;
    } else {
      p = top(s);
    }
    result[i] = i-p;
    push(&s, i);
  }
  deleteStack(&s);
  return result;
}
