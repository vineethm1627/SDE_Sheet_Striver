/*
    Problem Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < nums.size(); i++) {
        if(pq.size() < k) 
            pq.push(nums[i]);
        else if(nums[i] > pq.top()) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}