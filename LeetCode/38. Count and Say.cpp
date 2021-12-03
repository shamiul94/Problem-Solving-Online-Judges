// string push back is faster than + string additions
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string prevStr = countAndSay(n-1);
        
        int consecCount = 1; 
        string res = ""; 
        
        int i; 
        for(i = 1; i < prevStr.size(); i++) {
            if(prevStr[i] == prevStr[i-1]) {
                consecCount++;
            } else {
                res.push_back('0' + consecCount); 
                res.push_back(prevStr[i-1]);
                consecCount = 1; 
            }
        }
        
        res.push_back('0' + consecCount); 
        res.push_back(prevStr[i-1]); 
        
        return res; 
    }
};