#include <stdio.h>

int dectobin (int n) {
    if (n == 0) {
        return (0);
    } else {
        return (n % 2 + 10 * dectobin(n / 2));
    }
}

int main () {
    int n;
    scanf("%d", &n);
    printf("%d\n", dectobin(n));
    return 0;
}