/*
    Problem Link: https://leetcode.com/problems/find-median-from-data-stream/
*/

class MedianFinder {
public:
    priority_queue<int> maxHeap; // max of the left part
    priority_queue<int, vector<int>, greater<int>> minHeap; // min of right part

    void addNum(int num) {
        // left side of the array
        if(maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);
        
        // balance the 2 heaps
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size() - minHeap.size() >= 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else    
            return maxHeap.top();
    }
};