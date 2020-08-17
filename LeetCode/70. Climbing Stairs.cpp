#include <bits/stdc++.h>
using namespace std;

// This is basically a fibonacci series. You just need the last 2 numbers. 
// I couldn't come up with a fibonacci series itself at first. But when I implemented the 
// recursive solution, I could saw it. 

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1; 
        if(n == 2) return 2; 

        int prev = 2, prev_prev = 1, ways = 0 ; 
        for(int i = 3; i <= n; i++){
            ways = prev + prev_prev; 
            prev_prev = prev; 
            prev = ways; 
        }
        return ways; 
    }
};

class Solution1 {
public:
    int solve(int n, vector<int> &dp) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (dp[n] != -1) return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    /**
     * 1, 2, 3, 5, 8, 13
     * 
     * 
     */

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};