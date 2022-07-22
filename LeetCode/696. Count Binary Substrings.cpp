class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        if (s.length() == 0)
            return 0;

        bool isZeroRunning = (s[0] == '0');

        int consecutiveZeroCount = 0;
        int consecutiveOneCount = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (i > 0 && s[i] != s[i - 1])
            {
                ans += min(consecutiveZeroCount, consecutiveOneCount);

                if (s[i] == '0')
                    consecutiveZeroCount = 0;
                else
                    consecutiveOneCount = 0;
            }

            if (s[i] == '0')
            {
                consecutiveZeroCount++;
            }
            else
            {
                consecutiveOneCount++;
            }
        }

        ans += min(consecutiveZeroCount, consecutiveOneCount);

        return ans;
    }
};

/***

000001

**/