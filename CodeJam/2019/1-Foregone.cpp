//
// Created by heisenberg on 4/1/20.
//

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main_Wrong() {
    ll T, t = 0;
    cin >> T;
    while (T--) {
        t++;
        string n, a, b;
        cin >> n;
        cout << "Case #" << t << ": ";

        a = n;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != '4') {
                if (a[i] != '0') {
                    a[i] = a[i] - 1;
                    b = b + '1';
                } else {
                    b = b + '0';
                }
            } else {
                a[i] = '1';
                b = b + '3';
            }
        }

//        cout << a << " " << b << endl;
        bool chk = false;
        for (int i = 0; i < a.size(); i++) {
            if (!chk) {
                if (a[i] != '0') {
                    cout << a[i];
                    chk = true;
                }
            } else {
                cout << a[i];
            }
        }
        cout << " ";

        chk = false;
        for (int i = 0; i < b.size(); i++) {
            if (!chk) {
                if (b[i] != '0') {
                    cout << b[i];
                    chk = true;
                }
            } else {
                cout << b[i];
            }
        }
        cout << endl;
    }
}


int main2() {
    ll T, ttt = 0;
    cin >> T;
    while (T--) {
        ttt++;
        string n, a, b;
        cin >> n;

        cout << "Case #" << ttt << ": ";
        string half;
        int rem = 0, res;
        for (int i = 0; i < n.size(); i++) {
            int x = n[i] - '0';
//            cout << x << endl;
            x = rem * 10 + x;
            res = x / 2;
            char c = '0' + res;
            half = half + c;
//            cout << "hkshdf : " << half << endl;
            rem = x % 2;
        }
        a = half;
        b = half;

        if (rem == 1) {
            int addRem = 0;
            bool flag = false;
            for (int i = a.size() - 1; i >= 0; i--) {
                if (a[i] == '9') {
                    a[i] = '0';
                } else {
                    int x = a[i] - '0';
                    x++;
                    a[i] = x + '0';
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                string tem = "1";
                tem.append(a.begin(), a.end());
            }
        }

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '4' || b[i] == '4') {
                a[i] = a[i] - 2;
                b[i] = b[i] + 2;
            }
        }

        bool chk = false;
        for (int i = 0; i < a.size(); i++) {
            if (!chk) {
                if (a[i] != '0') {
                    cout << a[i];
                    chk = true;
                }
            } else {
                cout << a[i];
            }
        }
        cout << " ";

        chk = false;
        for (int i = 0; i < b.size(); i++) {
            if (!chk) {
                if (b[i] != '0') {
                    cout << b[i];
                    chk = true;
                }
            } else {
                cout << b[i];
            }
        }
        cout << endl;
    }
}