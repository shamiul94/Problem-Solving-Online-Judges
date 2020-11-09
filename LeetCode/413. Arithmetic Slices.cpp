/*
main observation: 

2,3,4 -> this array has 1 arithmetic seq. 
Now, add [5] to it. Now, [2,3,4], [2,3,4,5], [3,4,5] are the arithmetic seqs. 
We are not gonna save this number in our dp array cause it might cause overlap. 
but, we are gonna save the 'count of arithmetic seqs ENDING WITH 5'. 
number of artihmetic seqs ENDING WITH '5' ==  2. 
One thing to observe here: 
1. [2,3,4] was an arithmetic seq before but still it forms another new arithmetic seq - which is [2,3,4,5]
2. [3,4] was not a arithmetic seq before, but it is now after adding 5. cause it made [3,4,5] now. 

Points to take: 
1. at position i, if the num[i] can continue making the arithmetic seq using his previous elements, this element 
will inherit all the seqs [i-1] th element made. And a new seqs is made that it [3,4]+[5] = [3,4,5]. Hence, dp[i] = dp[i-1] + 1

Optimize more: 
1. dp[] array is not really needed as dp[i-1] is used only once. keep a dp variable and it will work. 

I will upload a video in Google photos or youtube. Watch from 4:00 to understand clearly. tough to explain by writing. 

*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        if (A.size() < 3) return 0;

        // dp[i] keeps the count of "How many subsequences are there ending with A[i]?"
        // vector<int> dp(A.size(), -1);

        int count_seq = 0;
        int dp = 0;

        int n = A.size();

        for (int i = 2; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp = dp + 1;
            } else {
                dp = 0;
            }

            count_seq += dp;
        }

        return count_seq;
    }
};

///////////

class Solution2 {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        if (A.size() < 3) return 0;

        // dp[i] keeps the count of "How many subsequences are there ending with A[i]?"
        vector<int> dp(A.size(), -1);

        int count_seq = 0;
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 0;
            }

            count_seq += dp[i];
        }

        return count_seq;
    }
};