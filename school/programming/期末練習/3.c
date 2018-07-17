#include <stdio.h>
#include <math.h>
#define MAX_NUM 100000

int isPrime(unsigned n); // 0: false 1: true

int main(int argc, char const *argv[]) {
  int primeNums[100000], count=0;
  int canGetDistant = 0, newDistant, distant;
  int rightIndex;
  newDistant = distant = 0;
  for (int i = 1; i < MAX_NUM; i++) {
    if (isPrime(i)) {
      primeNums[count++] = i;
      if (count >= 2) {
        canGetDistant = 1;
      }
      if (canGetDistant) {
        newDistant = primeNums[count-1] - primeNums[count-2];
        if (newDistant > distant) {
          distant = newDistant;
          rightIndex = count-1;
        }
      }
    }
  }
  printf("%d, %d\n", primeNums[rightIndex-1], primeNums[rightIndex]);
  return 0;
}

int isPrime(unsigned n) {
  int sqrtN = (int)sqrt(n);
  if (n < 2) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else if (n % 2 == 0) {
    return 0;
  } else {
    for (int i = 3; i <= sqrtN; i++) {
      if (n%i == 0) {
        return 0;
      }
    }
    return 1;
  }
}
