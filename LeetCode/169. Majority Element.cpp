
// boyer moore majority voting algorithm 

/**
This algorithm ASSUMES that the majority algorithm exists in the array more than n/2 times. 
If this condition is not met, this algorithm will not work. 
If this condition is met, this algo guarantees that the `candidate` avariable will contain the final result in it in the end

So, what do we do? 

if the vote count is 0, it means that we havent found any 'Majority' element YET or THIS FAR. 

as the number 


*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0; 
        int vote = 0; 
        
        for(int i = 0 ; i < nums.size(); i++) {
            if(vote == 0) {
                candidate = nums[i]; 
                vote++; 
            } else {
                if(candidate == nums[i]) {
                    vote++; 
                } else {
                    vote--; 
                }
            }
        }
        return candidate;
    }
};


///////////
class Solution1
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> um;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            if (++um[nums[i]] > floor(n / 2))
            {
                return nums[i];
            }
        }
        return -1;
    }
};

//////////////////////

class Solution2
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> um;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            if (um.find(nums[i]) == um.end())
            {
                // not found
                um[nums[i]] = 1;
            }
            else
            {
                // found
                um[nums[i]]++;
            }

            if (um[nums[i]] > floor(n / 2))
            {
                return nums[i];
            }
        }
        return -1;
    }
};