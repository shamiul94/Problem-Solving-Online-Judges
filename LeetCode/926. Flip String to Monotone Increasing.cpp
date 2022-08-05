class Solution
{
public:
    /**
        001110111000000

        001110111000000

        numOnes = 6

        {
            numFLips = 6
            numFlips = min(numOnes, numFLips) = min(6, 7) = 6
        }
    */

    int minFlipsMonoIncr(string s)
    {
        int numOnes = 0;
        int numFlips = 0;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '1')
            {
                numOnes++;
            }
            else
            {
                numFlips++;
                numFlips = min(numOnes, numFlips);
            }
        }
        return numFlips;
    }

    int minFlipsMonoIncr2(string s)
    {
        bool oneFound = false;

        int zeros = 0;
        int ones = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (oneFound == false && s[i] == '0')
                continue;

            if (oneFound == false && s[i] == '1')
                oneFound = true;

            // oneFound == true

            if (s[i] == '0')
            {
                zeros++;
            }
            else
            {
                ones++;
            }
        }

        return min(zeros, ones);
    }
};

/**
000100011

00111111110

00111111110

1. flip last 0 - 1 move
2. flip all the ones previously - 8 moves

numOnes = 8
numZeroes = 2



001100011100

001100011100

numOnes = 5

numFlips = 4
numFlips = min(numOnes, numFlips) = (5,4) = 4





*/

/**

0011011000
0000000000
0011111111


00110

00011000

000100100

1111111110

00001110


*/