#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    long long int n, m, sum = 0;
    int test, t = 0;
    cin >> test;
    while (t < test) {
        cin >> n >> m;
        int r;
        sum = m * n / 2;

        printf("Case %d: %lld\n", t + 1, sum);
        t++;
    }
    return 0;
}
 