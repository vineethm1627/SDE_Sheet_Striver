/*
    Problem Link: https://www.interviewbit.com/old/problems/largest-rectangle-in-histogram/
*/

int Solution::largestRectangleArea(vector<int> &arr) {
    int max_area = 0;
    int n = (int)arr.size();
    
    int pse[n]; // previous smaller element on the left
    int nse[n]; // next smaller element on the right
    
    stack<int> s; // store the indices of the elements: to calculate width later
    // compute previous smaller element
    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        // store the index
        pse[i] = s.empty() ? -1 : s.top();
        // push the current index in the stack
        s.push(i);
    }
    // empty the stack
    while(!s.empty())
        s.pop();
    
    // compute the next smaller element
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        
        // store the index
        nse[i] = s.empty() ? n : s.top();
        // push the current index in the stack
        s.push(i);
    }
    
    // compute the max area of each block: by expanding it both sides
    // until strictly smaller height block is found
    int cur_area;
    for(int i = 0; i < n; i++) {
        cur_area = arr[i] * (nse[i] - pse[i] - 1);
        if(cur_area > max_area)
            max_area = cur_area;
    }
    return max_area;
}
