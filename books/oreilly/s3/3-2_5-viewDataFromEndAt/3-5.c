// 3.2 連結リストの最後からn番目のノードを見つけよ
// 3.2の問題を1回の走査で解けるか

int viewDataFromEndAt(int n, struct list *list) {
  // 間隔が一定という性質
  int *temp, *ntemp, i;
  if (list == NULL) {
    return 0;
  }
  temp = ntemp = list;
  i = 0;
  while (i<n) {
    ntemp = ntemp->next;
    i += 1;
    if (ntemp == NULL) {
      return 0;
    }
  }
  while (ntemp != NULL) {
    temp = temp->next;
    ntemp = ntemp->next;
  }
  return temp->data;
}
