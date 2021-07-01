/*
    Problem Link: https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution {
public:
    void expandBothSides(string &s, int left, int right, int &start_idx, int &max_len, const int n) {
        // expand the palindrome on both sides if there is a match
        while(left >= 0 && right < n && s[left] == s[right]) {
            // keep the max len palindromic substring
            if(right - left + 1 > max_len) {
                start_idx = left;
                max_len = right - left + 1;
            }
            // expand the window
            left--;
            right++;
        }
    }
    
    string longestPalindrome(string &s) {
        const int n = (int)s.size();
        int start_idx = 0; // starting index where the substring starts
        int max_len = 1; // single char is considered to be a substring
        int left, right; // 2 pointers
        
        for(int i = 1; i < n; i++) {
            // consecutive pointers _ _
            left = i - 1;
            right = i;
            expandBothSides(s, left, right, start_idx, max_len, n);
            
            // pointers with 1 gap in between _x_
            left = i - 1;
            right = i + 1;
            expandBothSides(s, left, right, start_idx, max_len, n);
        }
        return s.substr(start_idx, max_len);
    }
};