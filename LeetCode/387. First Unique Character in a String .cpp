class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> found(26, 0);
        for(int i = 0 ; i < s.length(); i++){
            int fdx = s[i] - 'a';
            found[fdx]++;
        }
        for(int i = 0 ; i < s.length(); i++){
            int fdx = s[i] - 'a';
            if(found[fdx] == 1){
                return i;
            }
        }
        return -1;
    }
};