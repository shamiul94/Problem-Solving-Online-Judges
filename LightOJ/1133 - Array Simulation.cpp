#include<iostream>
#include<cstdio>

using namespace std;


void s(int arr[], int len) {
    int i, num;
    cin >> num;
    for (i = 0; i < len; i++) {
        arr[i] = arr[i] + num;
    }
}

void m(int arr[], int len) {
    int i, num;
    cin >> num;
    for (i = 0; i < len; i++) {
        arr[i] = arr[i] * num;
    }
}

void d(int arr[], int len) {
    int i, num;
    cin >> num;
    for (i = 0; i < len; i++) {
        arr[i] = arr[i] / num;
    }
}

void p(int arr[], int len) {
    int i, f, l, t;
    cin >> f >> l;
    t = arr[f];
    arr[f] = arr[l];
    arr[l] = t;
}

void r(int arr[], int len) {
    int i, t;
    for (i = 0; i < len / 2; i++) {
        t = arr[i];
        arr[i] = arr[(len - 1) - i];
        arr[(len - 1) - i] = t;
    }
}

void arrprint(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        cout << arr[i];
        (i == len - 1) ? (cout << endl) : (cout << " ");
    }
}

int main() {
    int arr[110] = {};
    int i, test, t = 0;
    cin >> test;
    while (t < test) {
        int arrsize, oper;
        cin >> arrsize >> oper;
        for (i = 0; i < arrsize; i++) {
            cin >> arr[i];
        }
        int time = 0;
        while (time < oper) {
            char name;
            scanf(" %c", &name);
            if (name == 'S') {
                s(arr, arrsize);
            } else if (name == 'M') {
                m(arr, arrsize);
            } else if (name == 'D') {
                d(arr, arrsize);
            } else if (name == 'R') {
                r(arr, arrsize);
            } else if (name == 'P') {
                p(arr, arrsize);
            }
            time++;
        }
        printf("Case %d:\n", t + 1);
        arrprint(arr, arrsize);
        t++;
    }
    return 0;
}
 