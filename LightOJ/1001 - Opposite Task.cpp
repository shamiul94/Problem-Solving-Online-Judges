#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
    int test, t = 0, num, i, j, tem = 0;
    cin >> test;
    while (t < test) {
        tem = 0;
        cin >> num;
        for (i = 0; i <= num; i++) {
            for (j = num; j >= 0; j--) {
                if (i + j == num && i <= 10 && j <= 10) {
                    printf("%d %d\n", i, j);
                    tem = 1;
                    break;
                }
            }
            if (tem == 1)
                break;
        }
        t++;
    }
    return 0;
}
 