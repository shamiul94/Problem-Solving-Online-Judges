#include <bits/stdc++.h>

#define print_vec(vec) for(int i = 0 ; i < vec.size(); i++){cout<<vec[i]<<" ";} cout << endl

using namespace std;

class WRONGSolution {
public:
    int solve(vector<int> &days, vector<int> &costs, vector<int> &dp, int dayIdx, int coveredTill) {
        if (dayIdx >= days.size()) return dp[dayIdx] = 0;
        if (dp[dayIdx] != -1) return dp[dayIdx];

        // covered more than or equal to current date.

        // why does this solution NOT work?
        // in this problem, every day is not necessary to compute cost.
        // for example, suppose you have bought a ticket for 30 days at day 2
        // that means, you are good till (2+30-1) = 31th day.
        // so, in this case, you don't need to buy anymore ticket at any day between 2 and 31.
        // so, if you normally traverse through every element in the array, you need to maintain
        // a bridge between 2 and 31 where, nothing happens to the elements between 2 and 31
        // except passing their data to each other.
        // but this doesn't always hold because some other recursion will overwrite it and cause
        // mismatch.
        // may be debugged later but i couldn't do it now.
        // even if you can debug it, it will have bad time complexity because, you are
        // traversing unnecessary values.
        // you should directly go to the index of our choice by lower_bound().
        if (coveredTill >= days[dayIdx]) {
            return dp[dayIdx] = solve(days, costs, dp, dayIdx + 1, coveredTill);
//            return dp[dayIdx] = (dp[dayIdx] == -1) ? solve(days, costs, dp, dayIdx + 1, coveredTill) : min(
//                    dp[dayIdx], solve(days, costs, dp, dayIdx + 1, coveredTill));
        }


        // less will only come this far.

        int minCost = INT_MAX;

        int willCover = 0;
//        for (int i = 0; i <= 2; i++) {
        for (int i = 2; i >= 0; i--) {
            if (i == 0) willCover = 1;
            else if (i == 1) willCover = 7;
            else willCover = 30;
            minCost = min(minCost, costs[i] + solve(days, costs, dp, dayIdx + 1, days[dayIdx] + willCover - 1));
        }
        return dp[dayIdx] = minCost;
    }

    int mincostTickets(vector<int> &days, vector<int> &costs) {
        vector<int> dp(days.size(), -1);
        int a = solve(days, costs, dp, 0, 0);

        print_vec(costs);
        print_vec(days);
        print_vec(dp);

        return a;
    }
};


class Solution {
public:
    int solve(vector<int> &days, vector<int> &costs, vector<int> &dp, int dayIdx) {
        if (dayIdx >= days.size()) return 0;

        if (dp[dayIdx] != -1) return dp[dayIdx];

        int minCost = INT_MAX;

        int willCover = 0;
        for (int i = 0; i <= 2; i++) {
            if (i == 0) willCover = 1;
            else if (i == 1) willCover = 7;
            else willCover = 30;

            // nextDay means the day immediately AFTER the LAST COVERED day.
            // for example, if you buy a tkt for 30 days at day 2,
            // you are covered till (2+30-1) = 31th day.
            // so, our nextDay = 32
            // we just need to find the lower_bound of it.
            // i looked for upper_bound of 31 but it creates some problems.
            // like - it will return the last element if it's not in the array
            // which will get wrong answer.
            int nextDay = days[dayIdx] + willCover;
            auto nextDayIdxIter = lower_bound(days.begin() + dayIdx, days.end(), nextDay);
            int nextIdx = static_cast<int>(nextDayIdxIter - days.begin());

            minCost = min(minCost, costs[i] + solve(days, costs, dp, nextIdx));
        }
        return dp[dayIdx] = minCost;
    }

    int mincostTickets(vector<int> &days, vector<int> &costs) {
        vector<int> dp(days.size(), -1);
        return solve(days, costs, dp, 0);
    }
};

int main() {
    Solution s;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> t{2, 7, 15};
    cout << s.mincostTickets(v, t) << endl;
}