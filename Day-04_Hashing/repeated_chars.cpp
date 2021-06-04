/*
    Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // edge case
        if(s.empty())
            return 0;
        
        int max_len = 1;
        // freq hashmap
        int visited[256] = {0};
        // apply sliding window
        int left = 0, right = 0, n = s.size();
        while(right < n) {
            // window expansion: take the current element into consideration
            visited[s[right]]++;
            // window contraction: if current char is duplicated in the current window
            while(visited[s[right]] > 1) {
                // remove the left most char from the window
                visited[s[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};