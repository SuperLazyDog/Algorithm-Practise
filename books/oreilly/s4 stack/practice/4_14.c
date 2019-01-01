// 用一个数组实现两个栈
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int stacks[1024];
int ll = 0, rl = 1024;
int lh = 0-1, rh = 1024+1;
void lpush(int data);
void rpush(int data);
int lpop();
int rpop();
void showl();
void showr();

void lpush(int data) {
  stacks[++lh] = data;
}
int lpop() {
  if (lh < 0) {
    return INT_MIN;
  }
  return stacks[lh--];
}
void showl() {
  int j = 0;
  for (int i = lh; i >= 0; i--) {
    printf("lstack[%d]: %d\n", j++, stacks[i]);
  }
  puts("\n");
}

void rpush(int data) {
  stacks[--rh] = data;
}

int rpop() {
  return stacks[rh++];
}

void showr() {
  int j = 0;
  for (int i = rh; i <= rl; i++) {
    printf("rstack[%d]: %d\n", j++, stacks[i]);
  }
  puts("\n");
}

int main(int argc, char const *argv[]) {
  for (int i = 0; i < 10; i++) {
    lpush(rand()%20);
    rpush(rand()%20);
  }
  showl();
  showr();
  return 0;
}
