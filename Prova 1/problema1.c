#include <stdio.h>

double harmonic (int n);

int main (void){

    int n;
    scanf("%d", &n);
    printf("%lf", harmonic(n));
}

double harmonic (int n){
    if (n == 1){
        return 1;
    }
    else{
        return (1.0/n) + harmonic(n-1);
    }
}