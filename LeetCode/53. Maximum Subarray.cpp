class Solution
{
public:
    
    // i implemented this on my own without even rememberng/looking at kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        
        int currRunSum = -1000000; 
        int maxSum = -1000000; 
        
        for(int i = 0; i < nums.size(); i++) {
            currRunSum = max(currRunSum + nums[i], nums[i]); 
            maxSum = max(maxSum, currRunSum);
        }    
        
        return maxSum;
    }


    int maxSubArray2(vector<int> &nums)
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