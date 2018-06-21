// 3.2 連結リストの最後からn番目のノードを見つけよ
// 3.2の計算量を改善できるか

// ハッシュ表を作る
// <位置, 値>

int **createHashFromList(struct list *list) {
  // { {postion1, data1}, {postion2, data2}, ... }
  int **hash, count=0, i;
  struct list *temp = list;
  while (temp != NULL) { // まずはリストの長さを計算0(n)
    temp = temp->next;
    count += 1;
  }
  hash = (int **)malloc(sizeof(int *)*count);
  for (i = 0; i < count; i++) {
    hash[i] = (int *)malloc(sizeof(int) * 2);
  }

  temp = list;
  i = 0;
  while (temp != NULL) {
    i++;
    hash[i][0] = i;
    hash[i][1] = temp->data;
    temp = temp->next;
  }

  return hash;
}

int viewDataFromEndAt(int n, struct list *list) {
  int **hash = createHashFromList(list);
  int count = 0;
  struct list *temp = list;
  while (temp != NULL) { // まずはリストの長さを計算0(n)
    temp = temp->next;
    count += 1;
  }
  if (count < n) {
    return  0;
  }
  return hash[count-n][1];
}
