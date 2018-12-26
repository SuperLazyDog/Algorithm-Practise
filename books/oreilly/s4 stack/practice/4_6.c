// 改进4_5的minStack, 减少空间复杂度
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

ListStack *getAdvancedMinStack(ListStack *head) {
  ListStack *new = createStack(), *temp = head, *temp2 = NULL, *temp3 = NULL;
  int isFirst = 1, min;
  if (!head) {
    deleteStack(&new);
    return NULL;
  }
  // 反转head
  while (temp) {
    temp3 = temp->next;
    temp->next = temp2;
    temp2 = temp;
    temp = temp3;
  }
  temp = temp2; // 原stack末尾
  // 生成minStack
  while (temp) {
    if (isFirst) {
      min = temp->data;
      push(&new, min);
      isFirst = 0;
    } else {
      if (min >= temp->data) {
        min = temp->data;
        push(&new, min);
      }
    }
    temp = temp->next;
  }
  // 再次反转head, 回到原样
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
