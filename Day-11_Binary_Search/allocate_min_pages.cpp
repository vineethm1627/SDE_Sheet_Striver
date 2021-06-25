/*
    Problem Link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
*/
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    // helper function: greedy approach: give max possible load to each student
    bool isPossible(int *arr, int n, int m, int cur_min) {
        int students = 1;
        int pages_read = 0;
        
        for(int i = 0; i < n; ) {
            // assign pages to the current student
            if(pages_read + arr[i] <= cur_min) {
                pages_read += arr[i];
                i++;
            }
            else {
                // assign pages to the new student;
                students++;
                pages_read = 0;
                // condition check
                if(students > m)
                    return false;
            }
        }
        return true;
    }

    int findPages(int arr[], int n, int m) {
        //code here
        // edge case: students are more than the number of books
        if(m > n)
            return -1;
        
        int result = INT_MAX;
        // count the total number of pages
        int sum = 0;
        for(int i = 0; i < n; i++) 
            sum += arr[i];
        
        // apply binary search
        int start = *max_element(arr, arr + n);
        int end = sum;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            // each student reads atmost mid number of pages [max upper_bound]
            if(isPossible(arr, n, m, mid)) {
                result = min(result, mid);
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return result;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}