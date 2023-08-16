#include <stdio.h>

int contagem (int n);

int main(void){
    int n;
    scanf("%d", &n);
    contagem(n);
    return 0;
}

int contagem (int n){
    if (n <= 0){
        return 0;
    }
    contagem(n-1);
    printf("%d ", n);
}