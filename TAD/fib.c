#include <stdio.h>

int fib (int n) {
    if (n == 0 || n == 1) {
        return (1);
    } else {
        return (fib(n-1) + fib(n-2));
    }
}

int main () {
    int n;
    scanf("%d", &n);
    n = n-1;
    printf("%d\n", fib(n));
    return 0;
}