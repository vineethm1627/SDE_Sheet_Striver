/*
    Problem Link: https://leetcode.com/problems/n-queens/
*/

// helper function to check if the queen is safe to be placed
bool isQueenSafe(vector<string> &chess, int row, int col) {
    // check vertically upwards
    for(int i = row - 1, j = col; i >= 0; i--) {
        // a queen is already there to attack
        if(chess[i][j] == 'Q')
            return false;
    }
    // check left upward diagonal
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        // a queen is already there to attack
        if(chess[i][j] == 'Q')
            return false;
    }
    // check right upward diagonal
    for(int i = row - 1, j = col + 1; i >= 0 && j < chess[0].size(); i--, j++) {
        // a queen is already there to attack
        if(chess[i][j] == 'Q')
            return false;
    }
    // it is safe to place the queen at chess[row][col]
    return true;
}

// helper function to place 1 Queen in one row
void printNQueens(vector<string> &chess, vector<vector<string>> &results, int row, int n) {
    // base case: all rows are processed ie. all the queens are placed
    if(row == n) {
        results.push_back(chess);
        return;
    }

    // go through all the options of placing queen in a column of a row
    for(int col = 0; col < n; col++) {
        // place the queen if it is a safe position
        if(isQueenSafe(chess, row, col)) {
            // place the queen
            chess[row][col] = 'Q';
            // recursive call: place queen in the next row
            printNQueens(chess, results, row + 1, n);
            // restore original config: remove the Queen for further iterations: backtracking
            chess[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> results;
    // chess board of nxn with all values: '.'
    vector<string> chess(n, string(n, '.'));
    // start placing queen in 0th ie. first row
    printNQueens(chess, results, 0, n);

    return results;
}