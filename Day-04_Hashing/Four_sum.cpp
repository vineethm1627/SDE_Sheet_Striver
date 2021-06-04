/*
    Problem Link: https://leetcode.com/problems/4sum/
*/

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    // base case: min 4 elements should be there
    if(nums.size() < 4)
        return {};
    // sort the vector
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 3; i++) {
        // avoid duplicates
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        for(int j = i + 1; j < n - 2; j++) {
            // avoid duplicates
            if(j > i + 1 && nums[j] == nums[j - 1])
                continue;
            // now apply pair sum
            int left = j + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    // avoid duplicates
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
                }
                else if(sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return result;
}

