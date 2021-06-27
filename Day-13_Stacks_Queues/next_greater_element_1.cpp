/*
    Problem Link: https://leetcode.com/problems/next-greater-element-i/
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m; // {element : next greater element}
        stack<int> s; // store indices
        int n = (int)nums2.size();
        // traverse from right to left
        for(int i = n - 1; i >= 0; i--) {
            // pop stack elements if current element is greater than top of stack
            while(!s.empty() && nums2[i] >= nums2[s.top()])
                s.pop();
            
            m[nums2[i]] = s.empty() ? -1 : nums2[s.top()];
            // push the current element on the stack
            s.push(i);
        }
        vector<int> results;
        for(int &x : nums1)
            results.push_back(m[x]);
        return results;
    }
};