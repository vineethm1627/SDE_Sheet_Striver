/*
    Problem Link: https://leetcode.com/problems/search-a-2d-matrix/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        // binary search
        int start = 0, end = rows * cols - 1;
        int mid, r, c;

        while(start <= end) {
            mid = start + (end - start) / 2;
            // find the value of row and col of the mid element
            r = mid / cols;
            c = mid % cols;
            if(matrix[r][c] == target)
                return true;
            // narrow down the search space
            if(target < matrix[r][c])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};