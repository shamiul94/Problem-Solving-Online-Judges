class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {

        int left = 0;

        unordered_map<char, int> umap; // char vs idx

        int maxLen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char currChar = s[i];

            umap[currChar] = i;

            if (umap.size() == 3)
            {
                int minIdxInMap = INT_MAX;
                for (auto pair : umap)
                {
                    minIdxInMap = min(minIdxInMap, pair.second);
                }

                left = minIdxInMap + 1;
                umap.erase(s[minIdxInMap]);
            }

            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
    }
};




/**

0   1   2   3   4   5   6   7   8   9   10  11  12
e   c   e   e   e   b   b   b   b   c   c   e   e

                                    l
                                                r

curr_unique_count = 2

map -> {


c - 10

e - 12

}



*/