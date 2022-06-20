class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int left = 0;

        unordered_map<int, int> umap;

        int maxLen = 0;

        for (int i = 0; i < fruits.size(); i++)
        {
            int currFruit = fruits[i];

            umap[currFruit] = i;

            if (umap.size() == 3)
            {
                int deleteIdx = INT_MAX;

                for (auto pair : umap)
                {
                    deleteIdx = min(deleteIdx, pair.second);
                }

                left = deleteIdx + 1;

                umap.erase(fruits[deleteIdx]);
            }

            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
    }
};

/**


1   2   3   2   2
i
        j

unique set - 1  2   3


*/