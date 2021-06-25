/*
    Problem Link: https://www.spoj.com/problems/AGGRCOW/
*/
#include <iostream>
#include <algorithm>
using namespace std;

// greedy helper function to place cows with min separation = mid
bool isPossible(int *arr, int n, int c, int min_sep) {
    // place the cow at the first position
    int prev_cow = arr[0], count = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] - prev_cow >= min_sep) {
            count++;
            prev_cow = arr[i];
            // all the cows are placed
            if(count == c)
                return true;
        }
    }
    return false;
}

// find the largest min. distance between 2 cows
int find(int *arr, int n, int c) {
    int start = 0, end = arr[n - 1] - arr[0];
    int max_sep = 0;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(isPossible(arr, n, c, mid)) {
            max_sep = mid;
            start = mid + 1;
        }
        else    
            end = mid - 1;
    }
    return max_sep;
}

int main() {

    int T, n, c;
    cin >> T;

    while(T--) {
        cin >> n >> c;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        sort(arr, arr + n);
        cout << find(arr, n, c) << endl;
    }

    return 0;
}

