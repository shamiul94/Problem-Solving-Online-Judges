class Solution {
public:
    vector <vector<string>> groupAnagrams(vector <string> &strs) {
        unordered_map <string, vector<string>> map;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            string hash = s;
            sort(hash.begin(), hash.end());

            map[hash].push_back(s);
        }
        vector <vector<string>> ans;
        auto it = map.begin();
        for (it = map.begin(); it != map.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};