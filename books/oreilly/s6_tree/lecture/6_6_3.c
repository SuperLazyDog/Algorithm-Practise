#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct b {
  int data;
  struct b *left;
  struct b *right;
} BinaryTreeNode;

void preOrder(BinaryTreeNode *root);

int main(int argc, char const *argv[]) {
  BinaryTreeNode a[10];
  for (int i = 0; i < 10; i++) {
    a[i] = *(BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    a[i].data = i;
    a[i].left = a[i].right = NULL;
  }
  int isLeft = 1;
  for (int i = 0; i < 9; i++) {
    if (isLeft) {
      isLeft = 0;
      a[i].left = &a[i+1];
    } else {
      isLeft = 1;
      a[i].right = &a[i+1];
    }
  }
  preOrder(&a[0]);
  return 0;
}

// 递归版
// void preOrder(BinaryTreeNode *root) {
//   if (root) {
//     printf("data: %d\n", root->data);
//     preOrder(root->left);
//     preOrder(root->right);
//   }
// }

void preOrder(BinaryTreeNode *root) {
  if (root) {
    /* code */
  }
}
