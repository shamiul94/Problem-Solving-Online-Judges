#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

int main() {
    long long int n, test, t = 0;
    cin >> test;
    while (test--) {
        char str[10];
        cin >> n;
        scanf(" %s", str);
        if (!strcmp(str, "Alice")) {
            if ((n % 3 == 1)) {
                printf("Case %d: Bob\n", t + 1);
            } else {
                printf("Case %d: Alice\n", t + 1);
            }
        } else {
            if ((n % 3 == 0)) {
                printf("Case %d: Alice\n", t + 1);
            } else {
                printf("Case %d: Bob\n", t + 1);
            }
        }
        t++;
    }

    return 0;
}