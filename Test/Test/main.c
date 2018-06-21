//
//  main.c
//  Test
//
//  Created by 徐伟达 on 2018/6/22.
//  Copyright © 2018年 徐伟达. All rights reserved.
//

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

int checkSymbol(char *str);

int main(int argc, const char * argv[]) {
	char **datas = (char *[]){"[]", "({A+B}/(x+y)/(m+n)) - {a-b/c}", "[]]"};
	for (int i = 0; i < 3; i++) {
		printf("%d: %d\n", i, checkSymbol(datas[i]));
	}
	return 0;
}

struct stack *createStack() { // 创建stack
	struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
	temp->count = 0;
	temp->head = NULL; //以 NULL 为终止符
	return temp;
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
	return stack->count == 0;
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


int checkSymbol(char *str) {
	// 1 true, 0 false
	struct stack *stack = createStack();
	char **targets = (char *[]){"()", "[]", "{}"};
	while (*str != '\0') {
		int selector = 2; // 0: (  1: ) 2: other
		for (size_t i = 0; i < 3; i++) {
			if (*str == targets[i][0]) {
				selector = 0;
				break;
			} else if (*str == targets[i][1]) {
				selector = 1;
				break;
			}
		}
		char temp = top(stack);
		int isError = 1; // 0 false, 1 true
		switch (selector) {
			case 0:
				push(stack, *str);
				break;
			case 1:
				for (size_t i = 0; i < 3; i++) { // 当前的结束括号是否对应stack首元素
					if (temp == targets[i][0]) {
						if (*str == targets[i][1]) {
							isError = 0;
						}
						break;
					}
				}
				if (isError == 1) {
					return 0;
				} else {
					pop(stack);
				}
				break;
			case 2:
				break;
		}
		str++;
	}
	deleteStack(stack);
	return 1;
}
