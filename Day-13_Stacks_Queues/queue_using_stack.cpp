/*
    Problem Link: https://leetcode.com/problems/implement-queue-using-stacks/
*/

class MyQueue {
public:
    // IMPLEMENTATION USING TWO STACKS: all operations would be performed on the output stack
    /*
        Amortized O(1) push and pop operations
    */
    /** Initialize your data structure here. */
    stack<int> input, output;
    MyQueue() {
            
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int e; // top element that needs to be returned
        // move elements from input to output
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        e = output.top();
        output.pop();
        return e;
    }
    
    /** Get the front element. */
    int peek() {
        // move elements from input to output
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
