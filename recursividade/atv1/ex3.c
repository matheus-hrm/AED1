#include <stdio.h>

int reverse(int n){
      if (n < 10) {
        return n;
    } else {
        int last = n % 10;
        int resto = n / 10;
        int restoReverso = reverse(resto);
        
        int count = 1;
        int temp = restoReverso;
        while (temp >= 10) {
            count *= 10;
            temp /= 10;
        }
        
        return (last * count * 10) + restoReverso;
    }
}

int main (void){
  int n;

  scanf("%d", &n);

  printf("%d", reverse(n));

  return 0;
}
