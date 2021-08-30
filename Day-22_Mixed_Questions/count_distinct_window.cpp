/*
    Problem Link: https://www.interviewbit.com/problems/distinct-numbers-in-window/#
*/

vector<int> Solution::dNums(vector<int> &A, int k) {
    vector<int> results;
    const int n = A.size();
    unordered_map<int, int> m;
    int count = 0;

    // insert the elements of the first window
    for(int i = 0; i < k; i++) {
        // count of unique elements
        if(m[A[i]] == 0)
            count++;
        m[A[i]]++;
    }
    results.push_back(count);
    // process the remaining elements
    for(int i = k; i < n; i++) {
        // remove the element going out of the current window
        if(m[A[i - k]] == 1)
            count--;
        m[A[i - k]]--;
        // add the current element in the window
        if(m[A[i]] == 0)
            count++;
        m[A[i]]++;
        // update the count in the vector
        results.push_back(count);
    }
    return results;
}
