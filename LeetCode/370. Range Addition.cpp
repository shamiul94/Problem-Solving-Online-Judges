class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> vec(length, 0); 
        
        for(int i = 0; i < updates.size(); i++) {
            vector<int> currUpdate = updates[i]; 
            
            int currStartIdx = currUpdate[0]; 
            int currEndIdx = currUpdate[1]; 
            int currIncrement = currUpdate[2]; 
            
            vec[currStartIdx] += currIncrement; 
            
            if(currEndIdx + 1 <= length - 1) {
                vec[currEndIdx + 1] += (-1 * currIncrement); 
            }
        }
        
        
        
        for(int i = 1; i < length; i++) {
            vec[i] = vec[i] + vec[i-1]; 
        }
        
        return vec; 
    }
};


/*

0 0 0 0 0 0
0 2 2 2 0 0
0 2 2 5 3 0


0 0 0 0  0  0
0 2 0 0 -2  0
0 2 0 3 -2 -3


*/