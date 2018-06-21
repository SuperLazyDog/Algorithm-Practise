// 記号の釣り合いをチェックするのにどうスタックを使うかを論じよ


// {} () []
// 只检查括号是否正确, 内容无视
// {()} + [{()}]

#include "stack.h"

int checkSymbol(char *str) {
  // 1 true, 0 false
  struct stack *stack = createStack();
  char **targets = (char *[]){"()", "[]", "{}"};
  while (str != '\0') {
    int selector = 2; // 0: (  1: ) 2: other
    for (size_t i = 0; i < 3; i++) {
      if (str == targets[i][0]) {
        selector = 0;
        break;
      } else if (str == targets[i][1]) {
        selector = 1;
        break;
      }
    }

    char temp = top(stack);
    int isError = 1; // 0 false, 1 true
    switch (selector) {
      case 0:
        push(stack, str);
        break;
      case 1:
        for (size_t i = 0; i < 3; i++) { // 当前的结束括号是否对应stack首元素
          if (temp == targets[i][0]) {
            if (str == targets[i][1]) {
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
    return 1;
  }
}
