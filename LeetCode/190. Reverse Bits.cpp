class Solution {
public:
    void set1(uint32_t &n, int idx) {
        n = n | (1 << idx);
    }

    void set0(uint32_t &n, int idx) {
        n = n & ~(1 << idx);
    }

    uint32_t reverseBits(uint32_t n) {
        for (int i = 0; i <= 15; i++) {
            int lo, hi;
            lo = i;
            hi = 32 - lo - 1;

            uint32_t mask;

            uint32_t hiBit, loBit;
            loBit = n & (1 << lo);
            hiBit = n & (1 << hi);

            if (loBit == 0) {
                set0(n, hi);
            } else {
                set1(n, hi);
            }

            if (hiBit == 0) {
                set0(n, lo);
            } else {
                set1(n, lo);
            }
        }
        return n;
    }
};