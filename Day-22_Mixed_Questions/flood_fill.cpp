/*
    Problem Link: https://leetcode.com/problems/flood-fill/
*/

class Solution {
    int rows, cols;
    int row_dirs[4] = {0, 0, -1, 1};
    int col_dirs[4] = {-1, 1, 0, 0};
public:
    
    // helper function
    void dfs_helper(vector<vector<int>> &image, int r, int c, int oldColor, int newColor) {
        // base cases
        if(r < 0 || c < 0 || r >= rows || c >= cols || image[r][c] != oldColor)
            return;
        // transform the color
        image[r][c] = newColor;
        // make recursive dfs calls on the neighbors
        for(int itr = 0; itr < 4; itr++) 
            dfs_helper(image, r + row_dirs[itr], c + col_dirs[itr], oldColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        this->rows = image.size();
        this->cols = image[0].size();
        
        int oldColor = image[sr][sc];
        // initiate a dfs call with the source pixel
        if(oldColor != newColor)
            dfs_helper(image, sr, sc, oldColor, newColor);
        return image;
    }
};