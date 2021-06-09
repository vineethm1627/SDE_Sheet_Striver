/*
    Problem Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1
*/

void subsets_helper(vector<int> &arr, int idx, int sum, int n, vector<int> &results) {
    // base case
    if(idx == n) {
        results.push_back(sum);
        return;
    }
    // recursive calls: there are 2 options
    // pick the current element
    subsets_helper(arr, idx + 1, sum + arr[idx], n, results);
    // do-not pick the current element
    subsets_helper(arr, idx + 1, sum, n, results);
    
}

vector<int> subsetSums(vector<int> arr, int n) {
    // Write Your Code here
    vector<int> results;
    subsets_helper(arr, 0, 0, n, results);
    // sort the vector 
    sort(results.begin(), results.end());
    
    return results;
}