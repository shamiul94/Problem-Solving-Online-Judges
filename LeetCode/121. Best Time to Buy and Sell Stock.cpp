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
