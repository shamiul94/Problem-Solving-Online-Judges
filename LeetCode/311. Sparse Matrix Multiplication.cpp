// O(n^3)
// naive bruteforce.

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        int rowA, rowB, colA, colB;

        rowA = A.size();
        colA = A[0].size();

        rowB = B.size();
        colB = B[0].size();

        vector<vector<int>> C(rowA, (vector<int>(colB, 0)));

        for (int i = 0; i < colB; i++) {
            for (int j = 0; j < rowA; j++) {
                for (int k = 0; k < colA; k++) {
                    C[j][i] += A[j][k] * B[k][i];
                }
            }
        }
        return C;
    }
};