// 3.6 ある連結リストが NULL で停止するかサイクルになっているかをチェックせよ
// 3.6 をO(n)で解けるか

// O(n)
int isCicle(struct list *list) {
  struct list *fastNode = list, *slowNode = list;
  if (list == NULL) {
    return 2; //判断できない
  }
  while (fastNode != NULL && slowNode != NULL) {
    fastNode = fastNode->next;
    if (fastNode == slowNode) {
      return 1;
    }
    if (fastNode == NULL) {
      return 0;
    }
    fastNode = fastNode->next;
    if (fastNode == slowNode) {
      return 1;
    }
    slowNode = slowNode->next;
  }
  return 0;
}
