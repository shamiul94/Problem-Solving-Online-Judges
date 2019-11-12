// my original solution - sliding window
// O(n)

class Solution1 {
public:
    int tArr[60] = {0};
    int sArr[60] = {0};

    bool isCandidate() {
        bool possible = true;
        for (int i = 0; i < 60; i++) {
            // if s has this character less times than t has
            // it's bad for us.
            if (sArr[i] < tArr[i]) {
                possible = false;
                break;
            }
        }
        return possible;
    }

    string minWindow(string s, string t) {
        for (int i = 0; i < t.size(); i++) {
            tArr[t[i] - 'A']++;
        }


        int n = s.size();
        int l = 0;


        int minWindow = INT_MAX;
        int start = -1, end = -1;
        string ans = "";

        for (int i = 0; i < n; i++) {

            char currChar = s[i];
            sArr[currChar - 'A']++;
            // cout << "hi" << endl;


            // not even eligible for minimizing as it
            // doesn't has the minimum quality.

            if (!isCandidate()) {
                continue;
            }

            while (isCandidate()) {
                if (i - l + 1 < minWindow) {
                    minWindow = i - l + 1;
                    start = l;
                    end = i;
                }

                sArr[s[l] - 'A']--;
                l++;
            }
            // cout << s.substr(l, i-l+1) << endl;
        }
        if (start == -1 || end == -1) return "";
        return s.substr(start, end - start + 1);
    }
};
/////////////////////

// optimized solution. - O(n)
// 97%, 98%

// my original solution - sliding window
// O(n)

class Solution {
public:

    // I could use an unordered_map instead of arrays.
    // to keep track of the character in t and the current window of s.
    int tArr[60] = {0};
    int sArr[60] = {0};

    string minWindow(string s, string t) {
        int uniqueT = 0;

        for (int i = 0; i < t.size(); i++) {
            // keeping track of characters in t
            tArr[t[i] - 'A']++;
            // checking if it's a new unique character.
            // we need to calculate the unique number because
            // in a window at first we have to make sure if all the characters
            // exist , then if the existing and desired characters are at
            // desired numbers.
            if (tArr[t[i] - 'A'] == 1) uniqueT++;
        }


        int n = s.size();
        int l = 0;


        int minWindow = INT_MAX;
        int start = -1, end = -1;
        string ans = "";

        // need means what value we need to call a window desired window.
        // got means what value we have got till now.
        // if a character fulfills it's quota number, we can increase the 'got' value
        // by 1.
        int need = uniqueT;
        int got = 0;

        for (int i = 0; i < n; i++) {

            char currChar = s[i];
            sArr[currChar - 'A']++;

            // iscandidate if (got == required)
            // checking if tArr[currChar - 'A'] != 0 --> if it exists in t
            // sArr[currChar - 'A'] == tArr[currChar - 'A'] --> if the number
            // of this character in this window is >= the occurrence in t.
            // if the both are fulfilled, got++
            if (tArr[currChar - 'A'] != 0 && sArr[currChar - 'A'] == tArr[currChar - 'A']) {
                got++;
            }


            // if l <= i --> self explanatory. sliding window requires it.
            // got == need the only condition of increasing l
            // i tries to make a good window, l tries to destroy it by shrinking the window.
            while (l <= i && got == need) {
                if (i - l + 1 < minWindow) {
                    minWindow = i - l + 1;
                    start = l;
                    end = i;
                }

                sArr[s[l] - 'A']--;

                // pretty similar as before.
                // if this character doesn't exist in t, ignore it.
                // if it exists, check if it's less than required.
                // if it's less, then do got--
                // it means, the window is dirty now
                if (tArr[s[l] - 'A'] != 0 && sArr[s[l] - 'A'] < tArr[s[l] - 'A']) {
                    got--;
                }

                l++;
            }
        }
        if (start == -1 || end == -1) return "";
        // substr(startIndex, length of the substring)
        return s.substr(start, end - start + 1);
    }
};
