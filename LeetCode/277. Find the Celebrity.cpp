/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution
{
public:
    int findCelebrity(int n)
    {
        int possibleCelebrity = 0; // exactly one celebrity is there

        for (int i = 0; i < n; i++)
        {
            if (knows(possibleCelebrity, i))
            {
                possibleCelebrity = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i != possibleCelebrity && (knows(possibleCelebrity, i) || !knows(i, possibleCelebrity)))
            {
                return -1;
            }
        }
        return possibleCelebrity;
    }
};

/**

[0, 1, 2]

knows(0,1)? == 1 --> 0 is NOT a celeb. 1 MAY BE a celeb.
knows(1,2)? == 0 --> 2 is NOT a celeb. 1 MAY BE a celeb.

*/
