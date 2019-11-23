class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <pair<char, int>> stk;
        pair<char, int> p;
        vector<int> v;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')') {
                continue;
            }
            p.first = s[i];
            p.second = i;
            if (s[i] == '(') {
                stk.push(p);
            } else if (s[i] == ')') {
                // makes a good pair
                if (stk.empty()) {
                    v.push_back(i);
                } else {
                    if (stk.top().first == '(') {
                        stk.pop();
                    } else {
                        v.push_back(i);
                    }
                }
            }
        }

        while (!stk.empty()) {
            v.push_back(stk.top().second);
            stk.pop();
        }
        string ans = "";

        int vs = v.size();
        if (vs == 0) return s;

        sort(v.begin(), v.end());

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < vs && i == v[j]) {
                j++;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }

    ///////////
    string minRemoveToMakeValid2(string s) {
        stack<int> st;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            if (s[i] == ')') {
                if (!st.empty()) st.pop();
                else s[i] = '*';
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};



/////////////////

