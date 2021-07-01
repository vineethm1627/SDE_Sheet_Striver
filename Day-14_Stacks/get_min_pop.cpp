/*
    Problem Link: https://practice.geeksforgeeks.org/problems/get-min-at-pop/1/
*/
#include <bits/stdc++.h>
using namespace std;

// function declarations
stack<int> _push(int arr[],int n);
void _getMinAtPop(stack<int>s);

//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n) {
    // your code here
    stack<int> s;
    for(int i = 0; i < n; i++)
        s.push(arr[i]);
    
    return s;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> s) {
    // your code here
    vector<int> arr;
    // add elements in the vector
    while(!s.empty()) {
        arr.push_back(s.top());
        s.pop();
    }
    stack<int> minStack;
    // we just store the min values in the minStack and all the values in the actual stac
    
    int n = arr.size();
    for(int i = n - 1; i >= 0; i--) {
        s.push(arr[i]);
        // add the last element in both the stacks
        // if value is lesser than minStack top, add in minStack
        if(minStack.empty() || arr[i] < minStack.top())
            minStack.push(arr[i]);
        else
            minStack.push(minStack.top());
    }
    // printing the elements of minStack
    while(!minStack.empty()) {
        cout << minStack.top() << " ";
        minStack.pop();
    }
    cout << endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    
	    
	}
	return 0;
}