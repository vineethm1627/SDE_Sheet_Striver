/*
    Problem Link: https://leetcode.com/problems/combination-sum/
*/

class Solution {
public:
    // helper function to find valid combinations
    void find_combinations(vector<int> &candidates, int target, int idx, vector<int> &path, vector<vector<int>> &results) {
        // base case
        if(idx == candidates.size()) {
            // the current path is a valid subset
            if(target == 0)
                results.push_back(path);
            return;
        }
        // we have 2 options:-
        // option-1: pick element with repetition
        if(candidates[idx] <= target) {
            // add the element in the path
            path.push_back(candidates[idx]);
            // recursive call with the same index: allows repetition of the current element
            find_combinations(candidates, target - candidates[idx], idx, path, results);
            // unpick the element for the next iteration: backtracking
            path.pop_back();
        }
        // option-2: dont pick the current element
        find_combinations(candidates, target, idx + 1, path, results);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> path;
        
        find_combinations(candidates, target, 0, path, results);
        return results;
    }
};