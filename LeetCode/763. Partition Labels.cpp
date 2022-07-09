class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26); 
        
        for(int i = 0 ; i < s.length(); i++) {
            lastIdx[s[i] - 'a'] = i; 
        }
        
        int last = 0; 
        int start = 0; 
        
        vector<int> ans; 
        
        for(int i = 0; i < s.length(); i++) {
            last = max(last, lastIdx[s[i] - 'a']); 
            
            if(last == i) {
                ans.push_back(last - start + 1); 
                start = last + 1; 
            }
        }
        
        return ans; 
    }
};