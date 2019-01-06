// 用栈判断回文
// 书上是对应....X....这种奇数长度的(题目就是奇数), 这里自制的奇偶都对应
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

// TODO: Review [复习此处的解法与思想, 并抄一遍书上解法]
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
