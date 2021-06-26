/*
    Problem Link: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
*/

class Solution{   
public:
    // helper function to find count of elements <= mid in a row
    int countSmallerThanEqualToMid(vector<int> &row, int n, int key) {
        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(row[mid] <= key)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start;
    }

    int median(vector<vector<int>> &matrix, int r, int c){
        // code here 
        // monotonic search space over possible matrix median value
        int start = 0, end = 2000;
        // apply binary search
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int count = 0; // <= mid (left part of final sorted merged array)
            // go through each row
            for(int i = 0; i < r; i++) {
                //count += countSmallerThanEqualToMid(matrix[i], r, mid);
                count += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());
            }
            // expand the left portion
            if(count <= (r * c) / 2)
                start = mid + 1;
            else 
                end = mid - 1;
        }
        return start;
    }
};