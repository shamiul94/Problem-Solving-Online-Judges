class Solution {
public:
    int reverse(int x) {
        long n = 0;
        long xx = x;
        int sign = 1;
        if (x < 0) sign = -1;

        xx = abs(xx);
        while (xx != 0) {
            int d = xx % 10;
            n = n * 10 + d;
            xx = xx / 10;
        }

        n = sign * n;

        if (n > INT_MAX || n < INT_MIN) return 0;
        return n;
    }
};