#include<stdio.h>

int T, ct = 1;

int main() {
    scanf("%d", &T);
    while (T--) {
        int a, b;
        scanf(" %d %d", &b, &a);
        printf("Case %d: %d\n", ct++, a + b);
    }
}