/*
    Problem Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k) {
        // your code here
        vector<int> results;
        deque<int> dq(k); // to store the indices of useful elements
        // front of the dq stores the index of the max window element
        
        // process the first window
        for(int i = 0; i < k; i++) {
            // remove element from back of dq if current element is greater than back element
            while(!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();
            // push the current index at the end of deque
            dq.push_back(i);
        }
        // process the remaining elements
        for(int i = k; i < n; i++) {
            // add max of the prev window in results
            results.push_back(arr[dq.front()]);
            
            // remove the elements going out of window
            while(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            // remove the useless elements
            while(!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();
            
            // add the current index at the end of deque
            dq.push_back(i);
        }
        // add max of last window
        results.push_back(arr[dq.front()]);
        return results;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;   
	}
	return 0;
}