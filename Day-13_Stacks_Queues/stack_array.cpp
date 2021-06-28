/*
    Problem Link: https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1
*/

#include<bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};


int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        MyStack *sq = new MyStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

//Function to push an integer into the stack.
void MyStack :: push(int x) {
    // Your Code
    // avoid overflow
    if(top >= 1000)
        return;
    arr[++top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop() {
    // Your Code  
    return top == -1 ? -1 : arr[top--];
}
