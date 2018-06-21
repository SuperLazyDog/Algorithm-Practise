
struct stack *createStack() { // 创建stack
  struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
  temp->count = 0;
  temp->head = NULL; //以 NULL 为终止符
}

void push(struct stack *stack, int data) { // push数据
  struct stack *temp = stack;
  struct listNode *node = (struct listNode *)malloc(sizeof(struct listNode));
  node->data = data;
  node->next = temp->head;
  temp->head = node;
  temp->count += 1;
}

int pop(struct stack *stack) { // pop数据
  if (isEmptyStack(stack)) {
    return -1; // 栈为空
  }
  struct listNode *tempNode = stack->head;
  int data = stack->head->data;
  stack->head = stack->head->next;
  stack->count -= 1;
  free(tempNode);
  return data;
}

int top(struct stack *stack) { // 查看第一个元素
  if (isEmptyStack(stack)) {
    return -1; // 栈为空
  }
  return stack->head->data;
}

int isEmptyStack(struct stack *stack) { // 检验是否为空
  stack->count == 0;
}


void deleteStack(struct stack *stack) { // 删除整个栈
  if (stack != NULL) {
    if (stack->head != NULL) {
      struct listNode *current = stack->head, *temp;
      while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
      }
    }
    free(stack);
  }
}
