// ある連結リストが NULL で停止するかサイクルになっているかをチェックせよ


// 前提: サイクルの場合,　丸ごとがサイクルになる (最初と最後と結ぶ)
int isCicle_0(struct list *list) {
  // 0: false 1: true 2: unknow
  struct list *temp = list;
  if (list == NULL) {
    return 2;
  }
  while (true) {
    temp = temp->next;
    if (temp == NULL) {
      return 0;
    } else if (temp == list) {
      return 1;
    }
  }
}


// 前提なし
// XXXXXXXXXXXXXXXX
int isCicle(struct list *list) {
  struct list *temp1, *temp2;
  temp1 = list;
  if (list == NULL) {
    return 2; //リスト自体が NULL で、判断はできない
  }
  while (temp1 != NULL) { // ここがミス、この解き方自体は無理
    temp2 = temp1->next;
    while (temp2 != NULL) {
      if (temp2 == temp1) {
        return 1;
      }
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }
}
