/*
    Problem Link: https://leetcode.com/problems/number-of-islands/
*/

class Solution {
public:
    // DFS Solution
    // denotes the 4 neighbors of a grid cell
    int row_dirs[4] = {0, 0, -1, 1};
    int col_dirs[4] = {-1, 1, 0, 0};
    int rows, cols;

    void dfs_helper(int r, int c, vector<vector<char>> &grid) {
        // base conditions: corner cases of the grid
        // when we encounter water, there won't be adjacent neighbor calls
        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
            return;
        // the current land block is visited
        grid[r][c] = '0';
        // recursive dfs calls for the neighbors
        for(int itr = 0; itr < 4; itr++)
            dfs_helper(r + row_dirs[itr], c + col_dirs[itr], grid);
    }

    
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        this->rows = grid.size();
        this->cols = grid[0].size();

        // init dfs call on each disconnected component
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs_helper(i, j, grid);
                }
            }
        }
        return count;
    }
    
};