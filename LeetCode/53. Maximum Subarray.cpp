class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxTotal = INT_MIN;
        int runningSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            runningSum = runningSum + nums[i];
            maxTotal = max(maxTotal, runningSum);
            if (runningSum < 0)
            {
                runningSum = 0;
            }
        }
        return maxTotal;
    }
};