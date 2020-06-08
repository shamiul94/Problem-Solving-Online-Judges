
// My own solution - 100% time, 44% memory.
class Solution {
public:
    vector<int> spiralOrder(vector <vector<int>> &matrix) {

        vector<int> ans;
        if (matrix.size() == 0) return ans;

        int startRow, endRow, startColm, endColm;
        int row, colm;

        // row == 0  && colm == 0 ? 

        startRow = 0;
        row = matrix.size();
        endRow = row - 1;
        startColm = 0;
        colm = matrix[0].size();
        endColm = colm - 1;

        // direction? 

        int total = row * colm;

        int t = 0;


        // right = 0, down = 1, left = 2, up = 3 

        int direction = 0; // right 

        int i, j;
        while (t < total) {
            switch (direction) {
                case 0:
                    i = startRow;
                    for (j = startColm; j <= endColm; j++) {
                        t++;
                        ans.push_back(matrix[i][j]);
                    }
                    startRow++;
                    break;
                case 1:
                    j = endColm;
                    for (i = startRow; i <= endRow; i++) {
                        t++;
                        ans.push_back(matrix[i][j]);
                    }
                    endColm--;
                    break;
                case 2:
                    i = endRow;
                    for (j = endColm; j >= startColm; j--) {
                        t++;
                        ans.push_back(matrix[i][j]);
                    }
                    endRow--;
                    break;
                case 3:
                    j = startColm;
                    for (i = endRow; i >= startRow; i--) {
                        t++;
                        ans.push_back(matrix[i][j]);
                    }
                    startColm++;
                    break;
            }
            direction = (direction + 1) % 4;
        }
        return ans;
    }
};