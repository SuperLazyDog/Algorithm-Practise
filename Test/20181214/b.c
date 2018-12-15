int solution(int A[], int N) {
  int max = A[0], i, count = 0, j, added = 0;
  for(i = 1; i < N; i ++) {
    if(A[i] > max) {
      max = A[i];
    }
  }
  for(i = 1; i <= max; i++) {
    for (j = 0; j < N; j++) {
      if (i <= A[j]) {
        if (!added) {
          added = 1;
          count ++;
        }
      } else {
        added = 0;
      }
    }
    added = 0;
  }
  return count;
}
