class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0; 
        int n = nums.size(); 
        
        for(int i = 0 ; i <= n; i++){
            x = x ^ i; 
        }
        
        for(int i = 0; i < nums.size(); i++){
            x = x ^ nums[i]; 
        }
        
        return x; 
    }
};

///

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = nums.size(); 
        
        for(int i = 0; i < nums.size(); i++){
            x = x ^ i; 
            x = x ^ nums[i]; 
        }
        
        return x; 
    }
};