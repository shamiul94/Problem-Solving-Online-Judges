#include <bits/stdc++.h>

using namespace std;
bool comparator(string s1, string s2) {
    return s1 < s2;
}

vector<string> sortBoxes(vector<string> boxList) {
    vector<pair<string, string>> oldBoxes;
    vector<pair<string, string>> newBoxes;
    vector<string> sortedBoxes;

    for(int i = 0 ; i < (int)boxList.size(); i++) {
        string currBox = boxList[i];

        string currBoxId = "";
        string currBoxVersion = "";

        for(int j = 0; j < (int) currBox.size(); j++) {
            if(currBox[j] != ' ') {
                currBoxId += currBox[j];
            } else {
                currBoxVersion = currBox.substr(j+1);
                break;
            }
        }

        if(currBoxVersion[0] >= 'a' && currBoxVersion[0] <= 'z') {
            // old box 
            oldBoxes.push_back({currBoxId, currBoxVersion});
        } else {
            newBoxes.push_back({currBoxId, currBoxVersion});
        }
    }

    std::sort(oldBoxes.begin(), oldBoxes.end(), comparator);

    for(int i = 0; i < (int)oldBoxes.size(); i++) {
        sortedBoxes.push_back(oldBoxes[i].first + ' ' + oldBoxes[i].second);
    }

    for(int i = 0; i < (int)newBoxes.size(); i++) {
        sortedBoxes.push_back(newBoxes[i].first + ' ' + newBoxes[i].second);
    }

    return sortedBoxes;
}