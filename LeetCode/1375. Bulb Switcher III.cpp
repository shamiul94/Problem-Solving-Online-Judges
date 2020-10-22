/*
Idea: If a light becomes blue, that means, every light before it including itself is turned on.
And, the maximum number of turned on bulbs is itself. Right? Let that sink in. 

If you got the idea, the code is just a two-liner. 
*/

class Solution {
public:
    int numTimesAllBlue(vector<int> &light) {
        vector<bool> on(light.size(), false);
        int maxBlue = 0, result = 0;
        for (int i = 0; i < light.size(); i++) {
            on[light[i] - 1] = true;
            while (maxBlue < light.size() && on[maxBlue]) //Increase the end of blue bulbs sequence starting from 0,
                maxBlue++;
            result += maxBlue == i + 1; //If number of blue bulbs is equal to number of switched on bulbs.
        }
        return result;
    }
};

class Solution1 {
public:
    int numTimesAllBlue(vector<int> &light) {
        int maxi = 0;
        int blue = 0;

        for (int i = 0; i < light.size(); i++) {
            maxi = max(maxi, light[i]);
            if (maxi == i + 1) {
                blue++;
            }
        }
        return blue;
    }
};
