int LPS[1000005] = {};
int N;

void generateLPSArray(string pattern) {
    N = static_cast<int>(pattern.length());
    int j, i;
    // initialize
    j = 0;
    LPS[0] = 0;

    for (i = 1; i < N;) {
        if (pattern[j] == pattern[i]) {
            LPS[i] = j + 1;
            i++;
            j++;
        } else { // pattern[j] != pattern[i]
            if (j > 0) {
                j = LPS[j - 1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}

int Solution::solve(string A) {
    memset(LPS , 0 , sizeof(LPS));
    string tem = A;
    int realStringLen = A.length();
    string modified = A + "#";
    reverse(tem.begin(), tem.end());
    modified += tem;
    generateLPSArray(modified);
    int lastIdxValue = LPS[N - 1];

    return ((realStringLen - lastIdxValue));
}
