/*
    Problem Link: https://leetcode.com/problems/counting-bits/
*/

class Solution {
public:
    // DP Solution
    vector<int> countBits(int n) {
        // edge case
        if(n == 0)
            return {0};

        vector<int> dp(n + 1);
        // base cases
        dp[0] = 0; // number of set bits in 0
        dp[1] = 1; // number of set bits in 1

        for(int i = 2; i <= n; i++) {
            // odd number
            if(i & 1)
                dp[i] = dp[i / 2] + 1;
            // even number
                dp[i] = dp[i / 2];
        }
        return dp;
    }
};
