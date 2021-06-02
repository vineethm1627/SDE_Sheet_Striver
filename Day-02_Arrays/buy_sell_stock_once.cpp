/* 
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    // maintain the min value of stock so far and find max profit if sold today
    int maxProfit(vector<int> &prices) {
        int max_profit = 0, min_val = prices[0];
        int n = prices.size(); // the number of days

        for(int i = 1; i < n; i++) {
            // buy the stock: available for lower price
            if(prices[i] < min_val)
                min_val = prices[i];
            else
            // sell the stock
                max_profit = max(max_profit, prices[i] - min_val); 
        }
        return max_profit;
    };
}