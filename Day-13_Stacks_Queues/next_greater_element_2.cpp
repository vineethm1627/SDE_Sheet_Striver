/*
    Problem Link: https://leetcode.com/problems/next-greater-element-ii/
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n); // to store the result
        stack<int> s; // to store the indices of the next greater number.
        // we are not storing numbers because of duplicates
        
        for(int i = 2 * n - 1; i >= 0; i--) {
            while(!s.empty() and arr[s.top()] <= arr[i % n]) {
                s.pop();
            }
            result[i % n] = (s.empty() ? -1 : arr[s.top()]);
            // push the current index on the stack
            s.push(i % n);
        }
        return result;
    }
};