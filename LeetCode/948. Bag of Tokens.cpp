


class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end()); 
        
        int i = 0, j = tokens.size() - 1; 
        int score = 0; 
        
        while(i <= j){ // i am checking equal for odd number of elements.
            if(P >= tokens[i]){
                P -= tokens[i]; 
                score++;
                i++; 
            } else if(score && i != j){
                P += tokens[j]; 
                score--;
                j--; 
            } else {
                break; 
            }
        }
        return score; 
    }
};

// DP - doesn't work
// class Solution2 {
// public:
    
//     // choice -> 0 = up, 1 = down, 2 = none 
    
//     int solve(vector<vector<int>> &dp, vector<int>& tokens, int i, int choice, int P, int score){
//         if(i >= tokens.size()){
//             return 0; 
//         }
//         if(dp[i][choice] != -1) return dp[i][choice]; 
        
//         int ret1 = 0, ret2 = 0, ret3 = 0 ; 
        
//         if(P >= tokens[i]){
//             ret1 = solve(dp, tokens, i+1, 0, P-tokens[i], score+1); 
//         }
        
//         if(score >= 1){
//             ret2 = solve(dp, tokens, i + 1, 1, P + tokens[i], score - 1); 
//         }
        
//         ret3 = solve(dp, tokens, i + 1, 2, P, score); 
        
//         return dp[i][choice] = max(ret1, max(ret2, ret3)); 
        
//     }
    
//     int bagOfTokensScore(vector<int>& tokens, int P) {
//         vector<vector<int>> dp(tokens.size(), vector<int> (3,-1)); // [score , up or down or not taken]
//         int score = 0; 
//         int up = solve(dp, tokens, 0, 0, P, score); 
//         int down = solve(dp, tokens, 0, 1, P, score); 
//         int not_taken = solve(dp, tokens, 0, 2, P, score); 
        
//         return max(up, max(down, not_taken));  
//     }
// };