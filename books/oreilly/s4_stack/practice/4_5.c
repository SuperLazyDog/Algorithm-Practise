// 设计 O(1) 的 获取stack最小值的函数
// 因为条件不同，这里写一个获取最小值stack的方法
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

ListStack *getMinStack(ListStack *head) {
  ListStack *new = createStack(), *temp = head, *temp2 = NULL, *temp3 = NULL;
  int isFirst = 1, min;
  // 把head全部倒置
  // a -> b -> c
  while (temp) {
    temp3 = temp->next;
    temp->next = temp2;
    temp2 = temp;
    temp = temp3;
  }
  temp = temp2;
  // 创建 minStack
  while (temp) {
    if (isFirst) {
      isFirst = 0;
      min = temp->data;
    } else {
      if (min > temp->data) {
        min = temp->data;
      }
    }
    push(&new, min);
    temp = temp->next;
  }
  // 把temp再次倒置，回到初始状态
  temp = temp2;
  temp2 = NULL;
  while (temp) {
    temp3 = temp->next;
    temp->next = temp2;
    temp2 = temp;
    temp = temp3;
  }
  return new;
}
