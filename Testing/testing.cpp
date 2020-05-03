#include <bits/stdc++.h>

using namespace std;


#define start 0
#define ending 1

class timestamp {
public:
    int id;
    int time;
    int type; // 0 = strt , 1 = end

    timestamp() {
        id = 0;
        time = 0;
    }

    timestamp(int id_, int time_, int type_) {
        id = id_;
        time = time_;
        type = type_;
    }
};

class Solution {
public:

    int stoi_(string &s) {
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            n = n * 10 + (s[i] - '0');
        }
        return n;
    }

    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> ans;

        stack<timestamp> stk;
        vector<timestamp> v;

        int colons = 0;

        for (int i = 0; i < logs.size(); i++) {
            string s = logs[i];

            string tem;
            timestamp ts;

            for (int j = 0; j < s.length(); j++) {
                if (s[j] != ':') {
                    tem += s[j];
                } else {
                    if (colons == 0) {
                        ts.id = stoi_(tem);
                    }
                    if (colons == 1) {
                        if (tem == "start") {
                            ts.type = 0;
                        } else {
                            ts.type = 1;
                        }
                    } else if (colons == 2) {
                        ts.time = stoi_(tem);
                    }
                    colons++;
                    tem = "";
                }
            }

            v.push_back(ts);
        }

        int intime = 0; // iner block time

        pair<int, int> duration;

//        stk.push(v[0]);
        for (int i = 0; i < v.size(); i++) {
            if (v[i].type == start) {
                stk.push(v[i]);
            } else {
                timestamp u = stk.top();
                if(u.type == start){
                    intime
                }

            }
        }

    }
};


/**

        (0_0  (1_2  -- inner block time --- 1_5)   0_6)


**/