#include <stdio.h>

int ackermann(int m, int n){
  if (m == 0){
    return n+1;
  }
  if (n == 0){
    return ackermann(m-1, 1);
  }
  if (n > 0 && m > 0){
    return ackermann(m-1, ackermann(m, n-1));
  }
  else {
    return 0;
  }
}

int main(void){
  int n, m;

  scanf("%d %d", &m, &n);

  printf("%d",ackermann(m,n));

  return 0;
}