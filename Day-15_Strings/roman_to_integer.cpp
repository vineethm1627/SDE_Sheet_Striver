/*
    Problem Link: https://leetcode.com/problems/roman-to-integer/
*/

class Solution {
    unordered_map<char, int> m = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
public:
    int romanToInt(string &s) {
        int result = 0, n = s.size();
        int curr = m[s[0]];
        for(int i = 0; i < n; i++) {
            // next will be 0 if we reach the end of the string
            int next = m[s[i + 1]];
            if(curr < next)
                result -= curr;
            else
                result += curr;
            curr = next;
        }
        return result;
    }
};