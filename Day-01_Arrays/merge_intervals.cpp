/*
    Problem Link: https://leetcode.com/problems/merge-intervals/
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        // sort on the basis of the start value
        sort(intervals.begin(), intervals.end());
        
        for(auto &interval : intervals) {
            // no common point: add the interval without merging
            if(results.empty() || interval[0] > results.back()[1])
                results.push_back(interval);
            else 
            // interval can be merged, update the ending value of the latest added interval
                results.back()[1] = max(results.back()[1], interval[1]);
        }
        return results;
    }
};