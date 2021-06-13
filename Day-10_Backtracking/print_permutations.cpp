/*
    Problem Link: https://leetcode.com/problems/permutations/
*/

// backtracking helper function
void permute_helper(vector<vector<int>> &results, vector<int> &nums, int idx) {
    // base case
    if(idx == (int)nums.size() - 1) {
        results.push_back(nums);
        return;
    }
    // recursive calls: fix the first position by all swaps
    for(int i = idx; i < (int)nums.size(); i++) {
        // fix the ith element at the start and permute over the remaining part
        swap(nums[i], nums[idx]);
        permute_helper(results, nums, idx + 1);
        // unswap for the next iteration: backtracking
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> results;
    permute_helper(results, nums, 0);

    return results;
}