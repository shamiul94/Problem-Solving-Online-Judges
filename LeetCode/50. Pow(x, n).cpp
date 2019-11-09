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