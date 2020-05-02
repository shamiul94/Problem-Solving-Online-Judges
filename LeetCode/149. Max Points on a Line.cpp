// Explanation : https://leetcode.com/problems/max-points-on-a-line/discuss/47124/C%2B%2B-slope-counter
// implement this one too ^^


// original: 20%, 7%

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // b | a | ?
    //   | c |
    // 	------
    //    0 | b | ?

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>> &points) {

        if (points.size() == 0) return 0;
        if (points.size() == 1) return 1;

        int maxi = INT_MIN;


        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, unordered_map<int, int>> um; // {(y1-y2) -> {(x1-x2) -> (occurrence)}}
            int itself = 1;

            for (int j = i + 1; j < points.size(); j++) {
                int x1, y1, x2, y2;
                x1 = points[i][0];
                y1 = points[i][1];
                x2 = points[j][0];
                y2 = points[j][1];

                if (x1 == x2 && y1 == y2) {
                    itself++;
                    continue;
                }

                // (y1 - y2) / (x1 - x2) == slope
                int numerator, denominator;
                numerator = y1 - y2;
                denominator = x1 - x2;

                // double slope;
                // slope = numerator / denominator;

                // {(y1-y2) == numerator -> {(x1-x2) == denom -> (occurrence)}}
//                 cout << "(" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ") --> " ;
//                 cout << numerator << "/" << denominator << " = " ;


//                if (denominator != 0) {
                int g = gcd(abs(numerator), abs(denominator));
                numerator /= g;
                denominator /= g;
//                }

                if (numerator == 0 || denominator == 0) {
                    numerator = abs(numerator);
                    denominator = abs(denominator);
                } else if (numerator < 0 && denominator < 0) {
                    numerator *= -1;
                    denominator *= -1;
                } else if (denominator < 0) {
                    numerator *= -1;
                    denominator *= -1;
                }

//                 cout << numerator << "/" << denominator << endl ;



                if (um.find(numerator) == um.end()) {
                    // numerator is not there
                    unordered_map<int, int> tem;
                    tem[denominator] = 1;
                    um[numerator] = tem;
                } else {
                    if (um[numerator].find(denominator) == um[numerator].end()) {
                        // num is thre but,
                        // denom is not there
                        um[numerator][denominator] = 1;
                    } else {
                        // num and denom both are there
                        um[numerator][denominator]++;
                    }
                }


            }

            // cout << "-------" << endl;

            maxi = max(maxi, itself);
            for (auto it1 = um.begin(); it1 != um.end(); it1++) {
                for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
                    // cout << it1->first << " " << it2->first << " " << it2->second << endl;
                    maxi = max(maxi, itself + it2->second);
                }
            }
        }

        return maxi;
    }
};

