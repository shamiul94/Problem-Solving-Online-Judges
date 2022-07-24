#define mod 1000000007

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);

        verticalCuts.push_back(w);
        verticalCuts.push_back(0);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxHorizontalDiff = -1;
        for (int i = 1; i < horizontalCuts.size(); i++)
        {
            maxHorizontalDiff = max(maxHorizontalDiff, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        int maxVerticalDiff = -1;
        for (int i = 1; i < verticalCuts.size(); i++)
        {
            maxVerticalDiff = max(maxVerticalDiff, verticalCuts[i] - verticalCuts[i - 1]);
        }

        long long int ans = ((long long int)(maxHorizontalDiff % mod) * (long long int)(maxVerticalDiff % mod)) % mod;

        return ans;
    }
};
