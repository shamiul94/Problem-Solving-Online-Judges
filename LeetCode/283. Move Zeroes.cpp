class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lo = 0; 
        int hi = 0; 
       
        for(hi = 0; hi < nums.size(); hi++) {
            if(nums[hi] != 0) {
                swap(nums[lo], nums[hi]); 
                lo++; 
            }
        }
        
    }
};



class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int lo = 0; 
        int hi = 0; 
        
        /*
        
        1 2 5 0 9 9
              i
                j
        
        1 2 3 4 5 5 0 0 0 0 0 0 0
                    i
                                j
        
        */
        
        while(lo < nums.size() && nums[lo] != 0) {
            lo++;
        }
        
        hi = lo; 
        
        while(hi < nums.size()) {
            if(nums[hi] == 0) {
                hi++; 
                continue; 
            } else {
                swap(nums[lo], nums[hi]); 
                lo++; 
                hi++; 
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int> &nums) {

        int n = nums.size();

        if (n == 0 || n == 1) return;

        int i = 0, j = 1;

        while (i < n && j < n) {
            if (nums[i] == 0 && nums[j] == 0) {
                j++;
            } else if (nums[i] == 0 && nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if (nums[i] != 0 && nums[j] == 0) {
                i++;
                j++;
            } else if (nums[i] != 0 && nums[j] != 0) {
                i++;
                j++;
            }
        }
    }
};

// 
class Solution2 {
public:
    void moveZeroes(vector<int> &nums) {
        int j = 0;
        // move all the nonzero elements at first
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};