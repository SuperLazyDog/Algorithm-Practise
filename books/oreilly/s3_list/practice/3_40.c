// 从 N 个元素循环列表删除第 M 的元素直到剩一个, 获取剩下的
// typedef struct circleNode {
//   int data;
//   struct circleNode *next;
// } CircleNode;
// CircleNode *newCircleNode(int data);
// void delete(CircleNode **head);
// void insertAtEnd(CircleNode **head, int data);
// void insertAtBegin(CircleNode **head, int data);
// void deleteFirst(CircleNode **head);
// void deleteLast(CircleNode **head);
// void showNodes(CircleNode *head);

//返回编号, 从0开始
// TODO: 查询为啥最后不能delete(&temp);
int getJosephuPosition(int n, int m) {
  CircleNode *head = newCircleNode(0), *temp = head, *temp2;
  for (int i = 1; i < n; i++) {
    insertAtEnd(&head, i);
  }
  showNodes(head);
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < m - 2; j++) {
      temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    temp2->next = temp2;
    delete(&temp2);
  }
  showNodes(temp);
  // delete(&temp);
  return temp->data;
}
