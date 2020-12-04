class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length(); 
        int len2 = num2.length(); 
        int len = max(len1, len2); 
        
        int idx1, idx2; 
        idx1 = len1-1; 
        idx2 = len2-1; 
        
        int a = 0, b = 0, sum = 0 , rem = 0, carry = 0; 
        string ans = ""; 
        
        for(int i = len-1; i >= 0; i--){
            if(idx1 < 0) {
                a = 0; 
            } else {
                a = num1[idx1] - '0'; 
            }
            
            if(idx2 < 0) {
                b = 0;
            } else {
                b = num2[idx2] - '0'; 
            }
            
            idx1--; 
            idx2--; 
            
            sum = a + b + carry;
            
            rem = sum % 10; 
            carry = sum / 10; 
            
            ans += (rem + '0'); 
            
        }
        if(carry != 0){
            ans += (carry + '0'); 
        }
        reverse(ans.begin(), ans.end()); 
        return ans; 
    }
};