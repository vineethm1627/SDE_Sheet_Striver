/*
    Problem Link: https://www.geeksforgeeks.org/count-number-subarrays-given-xor/
*/
/*
    Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
    Examples: 

    Input : arr[] = {4, 2, 2, 6, 4}, m = 6
    Output : 4
    Explanation : The subarrays having XOR of 
                their elements as 6 are {4, 2}, 
                {4, 2, 2, 6, 4}, {2, 2, 6},
                and {6}

    Input : arr[] = {5, 6, 7, 8, 9}, m = 5
    Output : 2
    Explanation : The subarrays having XOR of
                their elements as 5 are {5}
              and {5, 6, 7, 8, 9}
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int countXOR(int *arr, int n, int m) {
    unordered_map<int, int> freq;
    int count = 0, prefix_xor = 0;

    for(int i = 0; i < n; i++) {
        prefix_xor ^= arr[i];
        if(prefix_xor == m)
            count++;
        
        if(freq.find(prefix_xor ^ m) != freq.end())
            count += freq[prefix_xor ^ m];
        
        // update value in the map
        freq[prefix_xor]++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int m;
    cin >> m;

    cout << countXOR(arr, n, m);

    return 0;
}