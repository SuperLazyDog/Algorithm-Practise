// 連結リストの最後からn番目のノードを見つけよ
//　ps: 連結リスト
// struct list {
//   int data;
//   struct list *next;
// }
// O(n)


int viewDataFromEndAt(int n, struct list *list) {
  int count = 0, i = 0, index;
  struct list *temp = list;
  while (temp != NULL) {
    count += 1;
    temp = temp->next;
  }
  if (n > temp) {
    return 0; // nがデータのサイズを超えるエラー
  }
  index = count - 1 - n;
  temp = list;
  count = 0;
  while (count < index) {
    count += 1;
    temp = temp->next;
  }
  return temp->data;
}
