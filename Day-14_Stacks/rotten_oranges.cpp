/*
    Problem Link: https://leetcode.com/problems/rotting-oranges/
*/

class Solution {
    // denotes the four neighbours of a grid cell
    int row_dirs[4] = {0, 0, -1, 1};
    int col_dirs[4] = {-1, 1, 0, 0};
public:
    // BFS solution
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q; // to store the indices of the rotten oranges
        int fresh_oranges = 0, timer_count = 0;
        // initially insert all the indices with rotten oranges into the queue
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j])
                    fresh_oranges++;
            }
        }
        // if there are no fresh oranges, it will take 0 time.
        if(fresh_oranges == 0)
            return 0;
        // apply BFS
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto [r, c] = q.front();
                q.pop();
                // impact oranges in 4 directions
                for(int itr = 0; itr < 4; itr++) {
                    int new_r = r + row_dirs[itr];
                    int new_c = c + col_dirs[itr];
                    
                    // we only make a call if the neighbour exist and is a fresh orange
                    if(new_r < 0 || new_c < 0 || new_r >= rows || new_c >= cols || grid[new_r][new_c] != 1) 
                        continue;
                    // mark the fresh orange as rotten
                    grid[new_r][new_c] = 2;
                    // reduce fresh oranges count by 1
                    fresh_oranges--;
                    // add the neighbor in the queue
                    q.push({new_r, new_c});
                }
            }
            timer_count++;
        }
        return fresh_oranges > 0 ? -1 : timer_count - 1;
    }
};