/*
    Problem Link: https://leetcode.com/problems/implement-stack-using-queues/solution/
*/

class MyStack {
public:
    // IMPLEMENTATION USINIG A SINGLE QUEUE
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        // pop size - 1 elements and push them at the back
        // this ensures the current element added t the end of the queue comes to the front
        int size = q.size();
        for(int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */