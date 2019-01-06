// a, b，两字母构成的字符串, 最中间有X表示中间。确认是否是回文
int isPalindrome(char str[]) {
  int i = 0, j = 0;
  while (str[j]) {
    j++;
  }
  j = j - 1;
  while (i <= j && str[i] == str[j]) { // 等号可以去掉
    i++;
    j--;
  }
  return i <= j ? 0 : 1; // 等号可以去掉
}
