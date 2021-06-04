/*
    Problem Link: https://leetcode.com/problems/majority-element-ii/
*/

class Solution {
public:
    // Boyer Moore Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> results;
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        for(int &x : nums) {
            if(x == num1)
                count1++;
            else if(x == num2)
                count2++;
            else if(count1 == 0) {
                // reset values
                num1 = x;
                count1 = 1;
            }
            else if(count2 == 0) {
                // reset values
                num2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        // process the results
        count1 = count2 = 0;
        int n = nums.size();
        for(int &x : nums) {
            if(x == num1)
                count1++;
            else if(x == num2)
                count2++;
        }
        // condition checks
        if(count1 > n / 3)
            results.push_back(num1);
        if(count2 > n / 3)
            results.push_back(num2);
        
        return results;
    }
};