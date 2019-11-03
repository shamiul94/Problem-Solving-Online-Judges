#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    long long int test, t = 0, time, sqr, frst, last;
    long long int frstplc, lastplc, rowdiff, colmdiff, row, colm;

    cin >> test;

    while (t < test) {
        cin >> time;
        sqr = sqrt(time);
        frst = sqr * sqr;
        last = (sqr + 1) * (sqr + 1);
        frstplc = sqr;
        lastplc = sqr + 1;
        if (!(time - sqr * sqr)) {
            if (sqr & 1) {
                row = frstplc;
                colm = 1;
            } else {
                row = 1;
                colm = frstplc;
            }
        } else if (!(frst % 2)) {
            if (time < last - sqr + 1) {
                colm = frstplc + 1;
                row = time - frst;
            } else {
                row = lastplc;
                colm = last - time + 1;
            }

        } else {
            if (time < last - sqr + 1) {
                row = frstplc + 1;
                colm = time - frst;
            } else {
                colm = lastplc;
                row = last - time + 1;
            }
        }

        printf("Case %lld: %lld %lld\n", t + 1, colm, row);

        t++;
    }
    return 0;
}