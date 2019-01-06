// 用push, pop倒转stack
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

// 递归版
// TODO: Review [再看一遍插入最后的方法]
void insertAtBottom(ListStack **s, int data) {
  int temp;
  if (!*s) {
    push(s, data);
    return;
  }
  temp = pop(s);
  insertAtBottom(s, data);
  push(s, data);
}

void reverse(ListStack **s) {
  if (!s || !*s) { // stack为空
    return;
  }
  int data = pop(s);
  reverse(s);
  // 插入到最后
  insertAtBottom(s, data);
}

// 非递归版
// s   -> 5 4 3 2 1 0
// new -> 0 1 2 3 4 5
void reverse(ListStack **s) {
  ListStack *new = createStack();
  while (*s) {
    push(&new, pop(s));
  }
  while (new) {
    ListStack *temp2 = new, *temp3 = new;
    while (temp2->next) {
      temp3 = temp2;
      temp2 = temp2->next;
    }
    if (temp2 == temp3) { // 只剩一个元素
      new = NULL;
      temp3 = NULL;
    } else {
      temp3->next = NULL;
    }
    push(s, temp2->data);
    free(temp2);
  }
}
