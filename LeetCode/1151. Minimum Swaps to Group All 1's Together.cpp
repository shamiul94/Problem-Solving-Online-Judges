class Solution
{
public:
    int countOnes(vector<int> &data)
    {
        int countOne = 0;

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == 1)
            {
                countOne++;
            }
        }

        return countOne;
    }

    int minSwaps(vector<int> &data)
    {
        int windowLength = countOnes(data);

        int currWindowOneCount = 0;
        int maxOneInAnyWindow = 0;

        int lo = 0;
        int hi = 0;

        while (hi < data.size())
        {
            if (data[hi] == 1)
            {
                currWindowOneCount++;
            }

            if (hi - lo >= windowLength)
            {
                if (data[lo] == 1)
                {
                    currWindowOneCount--;
                }

                lo++;
            }

            maxOneInAnyWindow = max(maxOneInAnyWindow, currWindowOneCount);

            hi++;
        }

        return windowLength - maxOneInAnyWindow;
    }
    
    

    int minSwaps1(vector<int> &data)
    {
        int windowLength = countOnes(data);

        int currWindowOneCount = 0;
        int maxOneInAnyWindow = 0;

        for (int i = 0; i < windowLength; i++)
        {
            if (data[i] == 1)
            {
                currWindowOneCount++;
            }
        }

        maxOneInAnyWindow = max(maxOneInAnyWindow, currWindowOneCount);

        for (int i = 1; i <= data.size() - windowLength; i++)
        {
            if (data[i - 1] == 1)
            {
                currWindowOneCount--;
            }

            if (data[i + windowLength - 1] == 1)
            {
                currWindowOneCount++;
            }

            maxOneInAnyWindow = max(maxOneInAnyWindow, currWindowOneCount);
        }

        return windowLength - maxOneInAnyWindow;
    }
};