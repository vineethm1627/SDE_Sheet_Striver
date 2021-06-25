/*
    Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

// Time complexity of xor approach: O(n)

class Solution {
public:
    /*
        check condition for the left part:
        1st instance --> even index then check at next index that number is there or not
        2nd instance --> odd index then check at prev index that number is there or not
        
        use ^
        mid = 4 is even so we need the next index ie. 5 which is 4 ^ 1 ==> 100 ^ 1 = 101 ==> 5
        mid = 5 is odd so we need the prev index ie. 4 which is 5 ^ 1 ==> 101 ^ 1 = 100 ==> 4
    */
    int singleNonDuplicate(vector<int>& nums) {
        // if the single element is at the last position
        int start = 0, end = nums.size() - 2;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            // left part so move to the right
            if(nums[mid] == nums[mid ^ 1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return nums[start];
    }
};