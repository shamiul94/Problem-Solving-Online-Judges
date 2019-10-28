class Solution {
public:

    int n ;
    void recurse(vector<char>& s, int i){
        if(i >= n/2) return;
        swap(s[i], s[n-1-i]);
        recurse(s, i+1);
    }

    // faster than 75%
    void reverseStringRecursively(vector<char>& s) {
        n = s.size();
        recurse(s, 0);
    }

    // faster than 92%
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0 ; i < n/2; i++){
            swap(s[i], s[n-1-i]);
        }
    }
};