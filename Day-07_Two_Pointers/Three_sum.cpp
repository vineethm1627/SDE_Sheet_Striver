/*
    Problem Link: https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // base case: min 3 elements should be there
        if(nums.size() < 3)
            return {};
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++) {
            // edge case
            if(i > 0 and nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // now there are 3 cases
                if(sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    
                    // avoid duplicates
                    while(left < right and nums[left] == nums[left - 1])
                        left++;
                    // this is a major blunder
                    /*while(left < right and nums[right] == nums[right + 1])
                        right--;
                    */
                }
                else if(sum < 0)
                    left++;
                else 
                    right--;
            } 
        }
        return result;
    }
};