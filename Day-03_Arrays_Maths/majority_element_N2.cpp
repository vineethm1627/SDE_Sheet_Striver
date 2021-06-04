/*
    Problem Link: https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    // Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int result = 0, count = 0;
        
        for(const int &x : nums) {
            // first occurrence of the number
            if(count == 0) {
                result = x;
                // reset count value
                count = 1;
            }
            else if(result == x)
                count++;
            else
                count--;
        }
        return result;
    }
};