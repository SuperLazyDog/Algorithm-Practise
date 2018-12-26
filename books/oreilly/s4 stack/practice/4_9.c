// 回文结构是链表(即不能回溯)，如何判断是否是回文
// 又做了一遍, 和 3_37 一样
#include <stdio.h>
#include <stdlib.h>
typedef struct listNode {
  int data;
  struct listNode *next;
} ListNode;

ListNode *createList(int data) {
  ListNode *new = (ListNode *)malloc(sizeof(ListNode));
  new->next = NULL;
  new->data = data;
  return new;
}

void deleteList(ListNode **head) {
  if (!head || !*head) {
    return;
  }
  ListNode *temp = *head, *temp2;
  while (temp) {
    temp2 = temp->next;
    free(temp);
    temp = temp2;
  }
  *head = NULL;
}

int listLength(ListNode *head) {
  ListNode *temp = head;
  int i = 0;
  while (temp) {
    printf("List[%d]: %d\n", i, temp->data);
    i++;
    temp = temp->next;
  }
  printf("count: %d\n", i);
  puts("");puts("");
  return i;
}
void addElement(ListNode **head, int data, int position) {
  if (!head) {
    return;
  }
  ListNode *new = createList(data), *temp = *head, *temp2 = *head;
  if (position == 0 || !*head) {
    new->next = temp;
    *head = new;
  } else {
    int i = 0;
    while (temp && i < position) {
      temp2 = temp;
      temp = temp->next;
      i++;
    }
    temp2->next = new;
    new->next = temp;
  }
}
void deleteElement(ListNode **head, int position) {
  if (!head || !*head) {
    return;
  }
  ListNode *temp = *head, *temp2;
  if (position == 0) {
    temp = temp->next;
    free(*head);
    *head = temp;
  } else {
    int i = 0;
    while (temp && i < position) {
      temp2 = temp;
      temp = temp->next;
      i++;
    }
    if (temp) {
      temp2->next = temp->next;
      free(temp);
    }
  }
}

int isPalindrome(ListNode *head) {
  ListNode *slow = head, *fst = head, *temp1, *temp2, *temp3;
  int result = 0;
  if (!head) {
    return result;
  }
  // 寻找中间点
  while (fst) {
    fst = fst->next;
    if (!fst) {
      break;
    }
    fst = fst->next;
    slow = slow->next;
  }
  // 反转后半部分
  temp1 = temp2 = slow->next;
  temp3 = NULL; // 当前节点的上一个节点
  while (temp1) {
    temp2 = temp1->next;
    temp1->next = temp3;
    temp3 = temp1;
    temp1 = temp2;
  }
  // 比较
  temp1 = temp3; // temp1 是新开头(原末尾)
  temp2 = head;
  while (temp1) {
    if (temp1->data != temp2->data) {
      result = 0;
      break;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  result = 1;
  //再次反转后半部分
  temp1 = temp3;
  temp3 = NULL;
  while (temp1) {
    temp2 = temp1->next;
    temp1->next = temp3;
    temp3 = temp1;
    temp1 = temp2;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  ListNode *head = createList(1);
  addElement(&head, 2, 100);
  addElement(&head, 3, 100);
  addElement(&head, 4, 100);
  addElement(&head, 1, 100);
  listLength(head);
  printf("isPalindrome: %d\n", isPalindrome(head));
  listLength(head);
  deleteList(&head);
  return 0;
}
