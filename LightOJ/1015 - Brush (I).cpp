
#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    int test, t = 0;
    cin >> test;
    while (t < test) {
        int sum = 0;
        int stdnt, i, dust;
        scanf("\n%d", &stdnt);
        for (int i = 0; i < stdnt; i++) {
            cin >> dust;
            (dust >= 0) ? (sum = sum + dust) : (sum = sum);
        }
        printf("Case %d: %d\n", t + 1, sum);

        t++;
    }
}
 