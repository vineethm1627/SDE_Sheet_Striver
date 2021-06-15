/*
    Problem Link: https://leetcode.com/problems/sudoku-solver/
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    // helper function to check is char ch can be placed at (r, c)
    bool isValid(vector<vector<char>> &board, int r, int c, char ch) {
        for(int i = 0; i < 9; i++) {
            // check-1: already present in column c
            if(board[i][c] == ch)
                return false;
            // check-2: already present in row r
            if(board[r][i] == ch)
                return false;
            // check-3: 3x3 submatrix
            if(board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch)
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                // find the empty position
                if(board[i][j] == '.') {
                    // try putting in the correct value at this position
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(board, i, j, c)) {
                            // place the value 
                            board[i][j] = c;
                            // recursive call
                            // if valid number is placed no need to backtrack: fix the value at that position and move ahead
                            if(solve(board) == true)
                                return true;
                            else
                            // unplace the value for further iterations: backtracking
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        // everything is filled up: sudoku completed
        return true; // false was never returned
    }
};