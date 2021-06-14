/*
    Problem Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/  

class Solution{
    // lexographical order: DLRU
    int row_dirs[4] = {1, 0, 0, -1};
    int col_dirs[4] = {0, -1, 1, 0};
    string dir = "DLRU";
    
    public:
    
    void dfs_helper(int sr, int sc, vector<vector<int>> &matrix, int n, string moves,
    vector<string> &results) {
        // base case: destination is reached
        if(sr == n - 1 && sc == n - 1) {
            results.push_back(moves);
            return;
        }
        // base case: boundary conditions + cell not reachable + cell already visited
        if(sr < 0 || sc < 0 || sr >= n || sc >= n || matrix[sr][sc] == 0)
            return;
        
        // mark cur cell to be visited
        matrix[sr][sc] = 0;
        
        for(int idx = 0; idx < 4; idx++) {
            // recursive call: 4 directions
            dfs_helper(sr + row_dirs[idx], sc + col_dirs[idx], matrix, n, moves + dir[idx], results);
        }
        // unmark cell for further iterations: backtracking
        matrix[sr][sc] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        // Your code goes here
        vector<string> results;
        
        if(matrix[0][0] == 1 && matrix[n - 1][n - 1] == 1)
            dfs_helper(0, 0, matrix, n, "", results);
        
        return results;
    }
};