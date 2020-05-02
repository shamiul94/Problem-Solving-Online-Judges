// DFS with memorization

class Solution {
public:
    int dfs(vector <vector<int>> &matrix, int row, int colm, int i, int j) {
        if (i < 1 || i > row || j < 1 || j > colm) {
            return 0;
        }

        if (matrix[i][j] != -1) return matrix[i][j];

        if (i == row && j == colm) return matrix[i][j] = 1;

        return matrix[i][j] = dfs(matrix, row, colm, i + 1, j) + dfs(matrix, row, colm, i, j + 1);
    }

    int uniquePaths(int m, int n) {
        int row = n;
        int colm = m;

        vector <vector<int>> matrix(row + 1, vector<int>(colm + 1, -1));
        int a = dfs(matrix, row, colm, 1, 1);

        // for(int i = 0 ; i < matrix.size(); i++){
        //     for(int j = 0 ; j < matrix[i].size(); j++){
        //         cout << matrix[i][j] << " " ; 
        //     }
        //     cout << endl; 
        // }

        return a;
    }
};