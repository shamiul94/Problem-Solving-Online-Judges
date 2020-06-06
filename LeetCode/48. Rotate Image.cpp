#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;

void inline printMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


// concept: All rotation == (preprocessing the matrix) + (TRANSPOSING IT)
/// Link: https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image

class Solution {
public:
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
    void rotate(vector<vector<int>> &matrix) {
        unordered_set<string> visited;

        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix.size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }


/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
    void anti_rotate(vector<vector<int> > &matrix) {
        for (auto vi : matrix) reverse(vi.begin(), vi.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};


// 62% time, 5% space.
class Solution1 {
public:
    string Hash(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }

    void dfs(vector<vector<int>> &matrix, unordered_set<string> &visited, int i, int j, int prevNum) {
        string hash = Hash(i, j);
        if (visited.count(hash) != 0) {
            // visited
            matrix[i][j] = prevNum;
//            cout << "visited: " << i << "," << j << " --> " << matrix[i][j] << endl;
            return;
        }
        // not found == not visited yet.
        int nextPrev = matrix[i][j];
        matrix[i][j] = prevNum;
        visited.insert(hash);
//        cout << "not visited: " << i << "," << j << " --> " << matrix[i][j] << endl;
        //col2 == n-1-row1
        //row2 = col1
        dfs(matrix, visited, j, matrix.size() - 1 - i, nextPrev);
    }

    void rotate(vector<vector<int>> &matrix) {
        unordered_set<string> visited;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                string hash = Hash(i, j);
                if (visited.find(hash) == visited.end()) {
                    // not found == not visited yet
//                    cout << "starting from: " << i << "," << j << " == " << matrix[i][j] << endl;
                    dfs(matrix, visited, i, j, INT_MAX);
//                    cout << "##############" << endl;
                }
            }
        }
    }
};

class Solution2 {
public:
    void dfs(vector<vector<int>> &matrix, int i, int j, int prevNext, int steps) {
        if (steps == 5) {
            return;
        }
        //col2 == n-1-row1
        //row2 = col1
        int tem = matrix[i][j];
        matrix[i][j] = prevNext;
        dfs(matrix, j, matrix.size() - 1 - i, tem, steps + 1);
    }

    void rotate(vector<vector<int>> &matrix) {
        unordered_set<string> visited;

        // I will only access the top left quadrant.
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = 0; j < (matrix.size() + 1) / 2; j++) {
//                cout << i << " " << j << endl;
                dfs(matrix, i, j, matrix[i][j], 0);
            }
        }
    }
};

class Solution3 {
public:
    void dfs(vector<vector<int>> &matrix, int i, int j) {
        int steps = 0;
        int prev = matrix[i][j];
        while (steps != 5) {
            //col2 == n-1-row1
            //row2 = col1
            swap(prev, matrix[i][j]);
            int k = i;
            i = j;
            j = matrix.size() - 1 - k;
            steps++;
        }
    }

    void rotate(vector<vector<int>> &matrix) {
        unordered_set<string> visited;

        // I will only access the top left quadrant. Why?
        /// Because starting from those elements cover the whole array.
        /// so, it will work.

        for (int i = 0; i < matrix.size() / 2; i++) {
            /// (matrix.size() + 1) / 2 is needed for odd dimensions.
            /// Why? Use pen and paper to simulate.
            /// if we take the whole quadrant for odd dimensions, they will visit some cells twice which
            /// will cause multiple rotation in a single cycle.
            /// Not suitable for interview solution.
            /// Remember that every rotation is transpose along with some preprocessing.

            for (int j = 0; j < (matrix.size() + 1) / 2; j++) {
//                cout << i << " " << j << endl;
                dfs(matrix, i, j);
            }
        }
    }
};


int main() {

    vector<vector<int>> matrix2;
    int n = 5;
    int m = 1;
    for (int i = 0; i < n; i++) {
        matrix2.emplace_back();
        for (int j = 0; j < n; j++) {
            matrix2[i].push_back(m);
            m++;
        }
    }

    printMatrix(matrix2);

    cout << "--------------" << endl;
    vector<vector<int>> matrix = matrix2;

    Solution s;
    s.rotate(matrix);


    printMatrix(matrix);
    return 0;
}