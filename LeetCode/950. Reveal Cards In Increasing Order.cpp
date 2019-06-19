//https://leetcode.com/problems/reveal-cards-in-increasing-order/

#include "bits/stdc++.h"

#define ll long long

using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck) {
    vector<int> tem;
    for (int i = 0; i < deck.size(); i++) {
        tem.push_back(-1);
    }

    sort(deck.begin(), deck.end());

    int empty = static_cast<int>(deck.size()); // even if only one is empty in tem.

    int len = static_cast<int>(deck.size());
    int emptyFlag = 0;
    int j = 0;

    while (empty) {
        for (int i = 0; i < len; i++) {
            if (tem[i] == -1) {
                if (emptyFlag == 0) {
                    tem[i] = deck[j];
                    j++;
                    empty--;
                }
                emptyFlag = (emptyFlag + 1) % 2;
            }
        }
    }

    return tem;

}


int main() {
//    Input: [17,13,11,2,3,5,7]
//    Output: [2,13,3,11,5,17,7]

    vector<int> p;

    p.push_back(17);
    p.push_back(13);
    p.push_back(11);
    p.push_back(2);
    p.push_back(3);
    p.push_back(5);
    p.push_back(7);

    vector<int> t = deckRevealedIncreasing(p);
    for (int i = 0; i < t.size(); i++) {
        cout << t[i] << " ";
    }

    return 0;
}