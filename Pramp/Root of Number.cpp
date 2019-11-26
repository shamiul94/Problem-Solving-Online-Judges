#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double power(double x, int n) {
//    cout << "hi" << endl;
    if (x == 0) return 0;
    if (n == 0) return 1;
    if (n == 1) return x;

    // n is even
    // x ^ 4 = x ^ 2 * x ^ 2
    // x ^ 5 = x * x ^ 4 = x ^ x ^ 2 * x ^ 2

    double half = power(x, n / 2);
    double ret;
    if (n % 2 == 0) {
        ret = half * half;
    } else {
        ret = x * half * half;
    }
    return ret;
}

double root(double x, unsigned int n) {
    if (abs(x - 0) <= 1e-9) return 0;
    if (n == 0) return 1.0;
    if (n == 1) return x;

    // your code goes here
    double lo, hi, mid = 1;
    lo = 0;
    hi = x;
    double y;
    double mul;

//    mul = power(mid,n);

    while (lo <= hi) {
        mid = (lo + hi) / 2;

        mul = power(mid, n);

        if (abs(mul - x) <= 0.001) break;
        else {
            if (mul > x) {
                hi = mid;
            } else if (mul < x) {
                lo = mid;
            }
        }
    }
    return mid;
}

int main() {
    cout << root(7, 3) << endl;
    return 0;
}