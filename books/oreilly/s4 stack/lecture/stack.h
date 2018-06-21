#ifndef Stack_H
#define Stack_H

#include <stdio.h>
#include <stdlib.h>

// 栈的基本实现
struct listNode {
  int data;
  struct listNode *next;
};

struct stack {
  int count;
  struct listNode *head;
};

struct stack *createStack(void); // 创建stack 0(1)
void push(struct stack *stack, int data); // push数据 O(1)
int isEmptyStack(struct stack *stack); // 检验是否为空 O(1)
int pop(struct stack *stack); // pop数据 O(1)
int top(struct stack *stack); // 查看第一个元素 0(1)
void deleteStack(struct stack *stack); // 删除整个栈 0(n)

#endif /* Stack_H */
