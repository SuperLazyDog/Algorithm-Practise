// 用一个数组实现三个栈
// 左 中 右
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LENGTH 10
int stacks[LENGTH];
int ls = 0-1, ms = (LENGTH-1)/2-1, rs = LENGTH+1;
int lb = 0, mb = (LENGTH-1)/2, rb = LENGTH;
void pushl(int data);
int popl();
void showl();

void pushm(int data);
int popm();
void showm();

void pushr(int data);
int popr();
void showr();

void showAll() {
  puts("showAll");
  for (int i = 0; i < LENGTH; i++) {
    printf("data[%d]: %d\n", i, stacks[i]);
  }
  puts("");puts("");
}
int main(int argc, char const *argv[]) {
  for (int i = 0; i < 6; i++) {
    pushr(rand()%10);
  }
  // popr();popr();popr();popr();popr();popr();
  showr();
  showAll();
  for (int i = 0; i < 3; i++) {
    pushm(rand()%10);
  }
  showm();
  showr();
  showAll();
  return 0;
}

void pushl(int data) {
  // 需要检查是否撞到中栈
  if (ls + 1 >= mb) { // 中栈向右移动可能范围的一半的距离
    int distant = (rb - ms)/2;
    if (distant <= 0) { // 整个栈已满
      return;
    }
    for (int i = ms; i >= mb; i--) {
      stacks[i + distant] = stacks[i];
    }
    ms += distant;
    mb += distant;
  }
  stacks[++ls] = data;
}

int popl() {
  if (ls < lb) {
    return INT_MIN;
  }
  return stacks[ls--];
}

void showl() {
  int j = 0;
  puts("showl");
  for (int i = ls; i >= lb; i--) {
    printf("stackl[%d]: %d\n", j++, stacks[i]);
  }
  puts("");puts("");
}

void pushm(int data) {
  // 需要检查是否撞到右栈
  if (ms + 1 >= rs) { // 中栈向左移动可能范围的一半的距离
    int distant = (mb - ls)/2;
    if (distant <= 0) { // 整个栈已满
      return;
    }
    for (int i = mb; i <= ms; i++) {
      stacks[i - distant] = stacks[i];
    }
    mb -= distant;
    ms -= distant;
  }
  stacks[++ms] = data;
}
int popm() {
  if (ms < mb) {
    return INT_MIN;
  }
  return stacks[ms--];
}
void showm() {
  int j = 0;
  puts("showm");
  for (int i = ms; i >= mb; i--) {
    printf("stackm[%d]: %d\n", j++, stacks[i]);
  }
  puts("");puts("");
}

void pushr(int data) {
  // 需要检查是否撞到中栈
  if (rs - 1 <= ms) { // 中栈向左移动可能范围的一半的距离
    int distant = (mb - ls)/2;
    if (distant <= 0) { // 整个栈已满
      return;
    }
    for (int i = mb; i <= ms; i++) {
      stacks[i - distant] = stacks[i];
    }
    mb -= distant;
    ms -=distant;
  }
  stacks[--rs] = data;
}
int popr() {
  if (rs > rb) {
    return INT_MIN;
  }
  return stacks[rs++];
}
void showr() {
  int j = 0;
  puts("showr");
  for (int i = rs; i <= rb; i++) {
    printf("stackr[%d]: %d\n", j++, stacks[i]);
  }
  puts("");puts("");
}
