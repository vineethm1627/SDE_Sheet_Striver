/*
    Problem Link: https://leetcode.com/problems/find-the-duplicate-number/
*/  

class Solution {
public:
    // tortoise and hare approach to cycle detection
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow]; // 1 step
            fast = nums[nums[fast]]; // 2 steps
        }while(slow != fast);
        // cycle is detected: move fast to the head
        fast = nums[0];
        // move 1 step each
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        // value where cycle occurs: duplicate element
        return slow;
    }
};