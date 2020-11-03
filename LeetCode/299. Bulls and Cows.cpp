// With extra space

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<vector<int>> v(27, vector<int> (2, 0)); 
        for(int i = 0 ; i < secret.size(); i++){
            char char_secret, char_guess; 
            char_secret = secret[i]; 
            char_guess = guess[i]; 
            
            v[char_secret -'0'][0]++; 
            v[char_guess - '0'][1]++; 
        }
        
        int A = 0 , B = 0;
        
        for(int i = 0 ; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                A++; 
                v[secret[i]-'0'][0]--;         
                v[secret[i]-'0'][1]--;         
            }
        }
        
        for(int i = 0 ; i < v.size(); i++){
            B += min(v[i][0], v[i][1]); 
        }
        
        string s; 
        s = to_string(A) + "A" + to_string(B) + "B"; 
        
        return s; 
    }
};