// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39038/Kadane's-Algorithm-Since-no-one-has-mentioned-about-this-so-far-%3A)-(In-case-if-interviewer-twists-the-input)
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39039/Sharing-my-simple-and-clear-C%2B%2B-solution


// straight forward algo

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minElemSoFar = INT_MAX, maxProfitSoFar = INT_MIN;
        for (int i = 0; i < prices.size(); i++)
        {

            minElemSoFar = min(minElemSoFar, prices[i]);
            maxProfitSoFar = max(maxProfitSoFar, prices[i] - minElemSoFar);
        }
        return maxProfitSoFar;
    }
};

////////////////////

// kadane's algorithm
class Solution2
{
public:
    int maxProfit(vector<int> &prices)
    {
        int currRunSum = 0, maxSumSoFar = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            currRunSum = currRunSum + prices[i] - prices[i - 1];

            if (currRunSum < 0)
            {
                currRunSum = 0;
            }

            maxSumSoFar = max(maxSumSoFar, currRunSum);
        }
        return maxSumSoFar;
    }
};
