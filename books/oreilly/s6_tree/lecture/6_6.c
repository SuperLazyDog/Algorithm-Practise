// 树的遍历
#include <stdio.h>
#include <stdlib.h>

struct BinnaryTreeNode {
  int data;
  struct BinnaryTreeNode *left;
  struct BinnaryTreeNode *right;
};

void preOrder(struct BinnaryTreeNode *root);
void _preOrder(struct BinnaryTreeNode *root);

int main(int argc, char const *argv[]) {
  printf("%s\n", "hello");
  return 0;
}

// 前序
// 递归版
void preOrder(struct BinnaryTreeNode *root) {
  if (root) {
    printf("data: %d\n", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}
// 非递归版
void _preOrder(struct BinnaryTreeNode *root) {
  struct BinnaryTreeNode *queue = (struct BinnaryTreeNode *)malloc(sizeof(struct BinnaryTreeNode)*8);
  struct BinnaryTreeNode *current = root;
  int count=0;
  queue[count++] = current;
  while (count>0) {
    current = queue[--count];
    printf("data: %d\n", current->data);
    queue[count++] = current->right;
    queue[count++] = current->left;
  }
}
