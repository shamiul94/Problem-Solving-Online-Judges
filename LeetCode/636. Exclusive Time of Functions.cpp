//
// Created by heisenberg on 5/2/20.
//

#include <bits/stdc++.h>

using namespace std;


#define START 0
#define END 1

class interval {
public:
    int id;
    int start;
    int end;
    int duration;

    interval() {
        id = start = end = duration = 0;
    }
};


class timestamp {
public:
    int id;
    int type;
    int time;

    timestamp() {
        id = time = type = 0;
    }
};

bool comparatorByStart(const interval &int1, const interval &int2) {
    return int1.start < int2.start;
}

class Solution {
public:
    int stoi_(string &s) {
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            n = n * 10 + (s[i] - '0');
        }
        return n;
    }

    vector<int> solve(int n, vector<interval> &intervals) {

        vector<int> v(n, 0);
        sort(intervals.begin(), intervals.end(), comparatorByStart);

        // |-----------|
        //     |----|
        //###################
        // |---------|
        //               |-----------|
        for (int i = 0; i < intervals.size(); i++) {
            interval int1, int2;
            int1 = intervals[i];

            for (int j = i + 1; j < intervals.size(); j++) {
                int2 = intervals[j];

                if (int1.start > int2.end) {
                    continue;
                } else if (int2.start > int1.end) {
                    break;
                } else {
                    int1.duration -= int2.duration;
                    int1.start = int2.end + 1;
                    intervals[i] = int1;
                }
            }
        }

        for (int i = 0; i < intervals.size(); i++) {

            v[intervals[i].id] += intervals[i].duration;
        }
        return v;
    }

    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<interval> intervals;

        stack<timestamp> stk;
        for (int i = 0; i < logs.size(); i++) {
            string s = logs[i];
            string tem;
            int id = 0, start, end;
            int type = -1;
            int colons = 0;

            for (int j = 0; j < s.length(); j++) {
                if (s[j] != ':') {
                    tem += s[j];
                } else {
                    if (colons == 0) {
                        id = stoi_(tem);
                    } else if (colons == 1) {
                        if (tem == "start") {
                            type = START;
                        } else {
                            type = END;
                        }
                    }
                    colons++;
                    tem = "";
                }
            }

            timestamp ts;
            if (type == START) {
                start = stoi_(tem);
                ts.id = id;
                ts.time = start;
                ts.type = START;
                stk.push(ts);
            } else if (type == END) {
                end = stoi_(tem);
                ts.id = id;
                ts.time = end;
                ts.type = END;

                timestamp correspondingStart = stk.top();
                stk.pop();

                interval inter;
                inter.id = correspondingStart.id;
                inter.start = correspondingStart.time;
                inter.end = ts.time;
                inter.duration = inter.end - inter.start + 1;

                intervals.push_back(inter);
            }
        }


//        for (int i = 0; i < intervals.size(); i++) {
//            cout << intervals[i].id << " : " << intervals[i].start << " --> "
//                 << intervals[i].end << " == " << intervals[i].duration << endl;
//        }
        return solve(n, intervals);
    }
};

int main() {
    Solution s;
//    cout << "18,3,5,8,11,5" << endl;
//    vector<string> v{"0:start:1", "1:start:4", "1:end:6",
//                     "2:start:8", "2:end:12", "3:start:17",
//                     "4:start:20", "5:start:26", "5:end:30",
//                     "4:end:35", "3:end:40", "0:end:50"};

    vector<string> v{"0:start:0", "0:start:2",
                     "0:end:5", "0:start:6",
                     "0:end:6", "0:end:7"};
    s.exclusiveTime(1, v);
}