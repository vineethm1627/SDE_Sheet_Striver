/*
    Problem Link: https://leetcode.com/problems/coin-change/
*/

// DP Solution
int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    int n = coins.size();
    // dp[i] stores the min coins required to make amount "i"
    // base case
    dp[0] = 0;
    // sort the coins vector
    sort(coins.begin(), coins.end());
    // traverse the dp array
    for(int i = 1; i <= amount; i++) {
        // go through the coins with value <= i
        for(const int &c : coins) {
            if(c <= i) {
                int result = dp[i - c];
                if(result != INT_MAX)
                   dp[i] = min(dp[i], result + 1);  
            }
            else  // we are able to break since we sorted the coins vector
                break;
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}