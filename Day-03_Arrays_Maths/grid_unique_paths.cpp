/*
    Problem Link: https://leetcode.com/problems/unique-paths/
*/

// Recursion with Memoization

int countPaths(int sr, int sc, int dr, int dc, vector<vector<int>> &memo) {
        // base case: the bottom right destination is reached
        if(sr == dr && sc == dc)
            return 1;
        else if(sc > dc || sr > dr)
            return 0;
        
        // check for precomputed values
        if(memo[sr][sc] != -1)
            return memo[sr][sc];
        // recursive calls
        int h = countPaths(sr, sc + 1, dr, dc, memo); // horizontal move
        int v = countPaths(sr + 1, sc, dr, dc, memo); // vertical move
        
        return memo[sr][sc] = h + v;
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return countPaths(1, 1, m, n, memo);
    }

// Dynamic Programming

int uniquePaths(int m, int n) {
        // DP Solution
        // dp[i][j]: number of unique paths to arrive at the point (i, j)
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else 
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }