/*
    Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

class Solution {
public:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(target == nums[mid])
                return mid;
            
            if(nums[mid] >= nums[start]) {
                // part 1 of the array
                // check if target lies in the first part
                if(target >= nums[start] and target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else {
                // part 2 of the array
                if(target > nums[mid] and target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};
