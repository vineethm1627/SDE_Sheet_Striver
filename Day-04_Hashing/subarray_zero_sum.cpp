/*
    Problem Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

int maxLen(int arr[], int n) {
    // hashmap of cumulative sum --> index
    unordered_map<int, int> m;
    int max_len = 0, cur_sum = 0;

    for(int i = 0; i < n; i++) {
        cur_sum += arr[i];
        if(cur_sum == 0) {
            max_len = i + 1;
            continue;
        }
        // look for cur_sum in the hashmap
        if(m.find(cur_sum) != m.end()) 
            max_len = max(max_len, i - m[cur_sum]);
        else
            m[cur_sum] = i;
    }
    return max_len;
}