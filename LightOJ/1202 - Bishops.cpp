#include<iostream>
#include<cmath>

using namespace std;

int wb(int r, int c) {
    int tem = 0;
    if ((r % 2 == 0 && c % 2 == 0) || (r % 2 && c % 2)) {
        tem = 1;
    }
    return tem;
}

int main() {
    long long int r1, c1, r2, c2, t = 0, test, rd, cd;
    cin >> test;

    while (t < test) {
        cin >> r1 >> c1 >> r2 >> c2;
        rd = abs(r1 - r2);
        cd = abs(c1 - c2);

        if (wb(r1, c1) == wb(r2, c2)) {
            if (cd == rd) {
                cout << "Case " << t + 1 << ": 1" << endl;
            } else {
                cout << "Case " << t + 1 << ": 2" << endl;
            }
        } else {
            cout << "Case " << t + 1 << ": impossible" << endl;
        }

        t++;
    }
    return 0;
}
 