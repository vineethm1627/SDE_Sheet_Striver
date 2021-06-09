/*
    Problem Solving: https://leetcode.com/problems/subsets-ii/
*/

// find subsets with ds size = 1 then 2 .... n
void find_subsets(vector<int> &nums, int idx, int n, vector<int> &ds, vector<vector<int>> &results) {
    results.push_back(ds);
    for(int i = idx; i < n; i++) {
        // avoid duplicates
        if(i > idx && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        // recursive call
        find_subsets(nums, i + 1, n, ds, results);
        // backtracking: remove the added element
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> results;
    vector<int> ds;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    find_subsets(nums, 0, n, ds, results);
    
    return results;
}