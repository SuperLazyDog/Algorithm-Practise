// 判断由 X, S组成的栈的操作是否成立
// S: push X: pop

int canDo(char str[]) {
  int length = 0;
  for (int i = 0; str[i]; i++) {
    if (str[i] == 'S') {
      length++;
    } else if (str[i] == 'X') {
      length--;
      if (length < 0) {
        return 0;
      }
    }
  }
  return 1;
}
