/* original solution */

class Solution {
public:
    double recurse(double x, long n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double ret = 1;
        if (n % 2 == 0) {
            ret = recurse(x, n / 2);
            ret = ret * ret;
        } else {
            ret = x * recurse(x, n - 1);
        }
        return ret;
    }

    double myPow(double x, int n) {
        long N = n;
        int sign = (n < 0) ? -1 : +1;
        double ret = recurse(x, abs(N));
        if (sign == -1) return 1.0 / ret;
        else return ret;
    }
};

/** time - 100% , space - 100% **/

class Solution {
public:

    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        double ret = myPow(x, n / 2);
        if (n % 2 == 0) {
            ret = ret * ret;
        } else {
            if (n < 0) {
                ret = (1 / x) * ret * ret;
            } else {
                ret = x * ret * ret;
            }
        }
        return ret;
    }
};

