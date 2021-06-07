/*
    Problem Link: https://leetcode.com/problems/max-consecutive-ones/
*/

int findMaxConsecutiveOnes(vector<int> &nums) {
    int max_count = 0, count = 0;

    for(const int &x : nums) {
        if(x == 1)
            count++;
        else    
            count = 0;

        max_count = max(max_count, count); 
    }
    return max_count;
}