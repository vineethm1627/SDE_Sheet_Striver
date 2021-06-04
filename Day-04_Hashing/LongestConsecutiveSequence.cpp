/*
    Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(int x : s) {
            // x will be the first number of the sequence
            // if x - 1 exists then current x is already a part of the sequence.
            if(s.find(x - 1) != s.end())
                continue;
            int cur_len = 1;
            while(s.find(++x) != s.end())
                cur_len++;
            
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};