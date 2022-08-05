class Solution {
public:
    
    void backtrack(string &digits, int idx, vector<string> &letters, string &currStr, vector<string> &result) {
        if(idx == digits.size()) {
            // cout << "hi" << endl;
            result.push_back(currStr);
            return;
        }
        
        int currDigit = digits[idx] - '0'; 
        
        string currentNumberLetters = letters[currDigit]; 
        
        // cout << currDigit << " " << currentNumberLetters << endl; 
        
        for(int i = 0; i < currentNumberLetters.size(); i++) {
            currStr += currentNumberLetters[i]; 
            // cout << currStr << " " << idx << endl; 
            backtrack(digits, idx+1, letters, currStr, result); 
            currStr.pop_back(); 
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0) return vector<string> ();
        
        vector<string> letters = {"#", "#","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> result; 
        
        
        
        string currStr = "";
        
        backtrack(digits, 0, letters, currStr, result);
        
        return result;
    }
};



class Solution2 {
public:

    void solve(vector <string> &ans, vector <string> &map, string &digits, string &curr, int idx) {
        if (idx >= digits.length()) {
            ans.push_back(curr);
            return;
        }

        char c = digits[idx];
        int n = c - '0';

        string letters = map[n];

        for (int i = 0; i < letters.length(); i++) {
            curr += letters[i];
            solve(ans, map, digits, curr, idx + 1);
            curr.pop_back();
        }
    }

    vector <string> letterCombinations(string digits) {
        vector <string> ans;

        if (digits.length() == 0) return ans;

        vector <string> map(10);// 0-9

        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";

        string curr;
        solve(ans, map, digits, curr, 0);
        return ans;
    }
};