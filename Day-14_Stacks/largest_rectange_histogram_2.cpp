/*
    Problem Link: https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1/
*/

class Solution {
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n) {
        // Your code here
        stack<long long> s;
        long long max_area = 0, cur_area = 0;
        
        // i would be the index of nse for top of stack
        // the element below top of stack would be the pse
        // pse and nse are used to provide the width of the rectangle
        // edge cases: when s is empty ie pse doesn't exist we take pse to be 0
        // when nse doesn't exist we take nse to be n
        
        for(int i = 0; i <= n; i++) {
            // i == n will count for elements with no nse: so take nse = n
            while(!s.empty() && (i == n || arr[i] <= arr[s.top()])) {
                // i is the nse
                // pse is the element below top of stack
                // arr[tp] is the height
                // width = nse - pse - 1
                long long tp = s.top();
                s.pop();
                cur_area = arr[tp] * (s.empty() ? i : i - s.top() - 1);
                if(cur_area > max_area)
                    max_area = cur_area;
            }
            // insert current index in the stack
            s.push(i);
        }
        return max_area;
    }
};
