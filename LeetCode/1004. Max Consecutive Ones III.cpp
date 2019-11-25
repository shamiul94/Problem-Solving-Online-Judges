class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int zerosInThisWindow = 0;
        int longest = 0;

        int n = A.size();
        int lo = 0;
        for (int hi = 0; hi < n; hi++) {
            if (A[hi] == 1) {
                longest = max(longest, hi - lo + 1);
                continue;
            }

            // if 0
            zerosInThisWindow++;

            if (zerosInThisWindow > K) {
                while (lo <= hi && zerosInThisWindow > K) {
                    if (A[lo] == 0) {
                        zerosInThisWindow--;
                    }
                    lo++;
                }
            }

            longest = max(longest, hi - lo + 1);
        }
        return longest;
    }
};