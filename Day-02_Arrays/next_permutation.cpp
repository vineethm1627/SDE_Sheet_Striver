/*
    Problem Link: https://leetcode.com/problems/next-permutation/
*/

class Solution {
public:
    vector<int> nextPermutation(vector<int> &arr) {
    int i, n = arr.size();
    // from the back, find the first element: arr[i] < arr[i + 1]
    for(i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1])
            break;
    }
    // reverse the entire sequence: 5 4 3 2 1 --> 1 2 3 4 5
    if(i < 0) {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    // from the back, find the first element: arr[j] > arr[i]
    for(int j = n - 1; j > i; j--) {
        if(arr[j] > arr[i]) {
            swap(arr[i], arr[j]);
            break;
        }
    }
    // reverse the part from i+1 till end
    reverse(arr.begin() + i + 1, arr.end());
    return arr;
}

};