/*
    Problem Link: https://leetcode.com/problems/set-matrix-zeroes/
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();
        bool fillFirstCol = false;
        // matrix[0][0] = 0, implies fill the first row with 0s
        // we are considering aux arrays as the first row and first col
        for(int i = 0; i < rows; i++) {
            // first col should be set to 0
            if(matrix[i][0] == 0)
                fillFirstCol = true;
            for(int j = 1; j < cols; j++) {
                // mark 0 in the corresponding row and col
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        // set matrix elements to 0s
        // traverse from bottom right to top; from right to left
        for(int i = rows - 1; i >= 0; i--) {
            // exclude the first col
            for(int j = cols - 1; j >= 1; j--) {
                // check for the marking in the aux first row / col array
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            // set the first col elements to 0 if required
            if(fillFirstCol)
                matrix[i][0] = 0;
        }
     }
};