// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int temp = A[0], count = 0;
    while (temp != -1) {
      count++;
      temp = A[temp];
    }
    if (temp == -1) {
      count++;
    }
    if (count > N) {
      count = N;
    }
    return count;
}
