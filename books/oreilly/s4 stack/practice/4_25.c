// 用栈改善 4_24 O(n^2). O(n)
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
typedef struct item {
  int i, h;
} Item;
// TODO: Review [再复习一遍]
int getLargestOblong(int a[], int n) {
  Item items[n], temp;
  int max = 0, current = -1, tempS;
  for (size_t i = 0; i < n; i++) {
    if (current == -1 || items[current].h < a[i]) { // 插入
      current++;
      items[current].h = a[i];
      items[current].i = i;
      continue;
    }
    while (current != -1 && items[current].h > a[i]) {
      temp = items[current];
      current--;
      tempS = temp.h * (temp.i - (current == -1 ? -1:items[current].i));
      if (tempS > max) {
        max = tempS;
      }
    }
    if (items[current].h < a[i]) {
      current++;
      items[current].h = a[i];
      items[current].i = i;
    }
  }
  while (current != -1) {
    temp = items[current];
    current--;
    tempS = temp.h * (temp.i - (current == -1 ? -1:items[current].i));
    if (tempS > max) {
      max = tempS;
    }
  }
  return max;
}
