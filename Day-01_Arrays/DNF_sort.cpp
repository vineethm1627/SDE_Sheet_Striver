/*
    problem link: https://leetcode.com/problems/sort-colors/
*/ 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // use DNF sort
        // region of 0s{0, low}, region of 1s{low, mid}, region of 2s{high, n - 1}
        // uncertain region or unsorted region{mid, high}.
        // we need to shrink this region{mid, high}.
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high) {
            if(nums[mid] == 0) 
                swap(nums[mid++], nums[low++]);
            else if(nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};