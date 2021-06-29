/*
    Problem Link: https://www.interviewbit.com/problems/nearest-smaller-element/
*/

vector<int> Solution::prevSmaller(vector<int> &arr) {
    stack<int> s;
    int n = (int)arr.size();
    vector<int> results(n);
    
    for(int i = 0; i < n; i++) {
        // pop elements from stack if arr[i] <= top of stack elements
        while(!s.empty() && arr[i] <= arr[s.top()])
            s.pop();
        results[i] = s.empty() ? -1 : arr[s.top()];
        // insert the current element's index in the stack
        s.push(i);
    }
    return results;
}