/*
    Merge sort is a divide and conquer algorithm.
    It divides the input array into 2 halves and then merges the 2 sorted halves.
    Time complexity = O(nlogn)
*/
#include <iostream>
using namespace std;

// helper function to merge 2 sorted arrays
void merge(int *arr, int start, int mid, int end) {
    int n1 = mid - start + 1; // mid is included
    int n2 = end - mid;

    // temp arrays
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for(int i = 0; i < n1; i++)
        right[i] = arr[mid + i + 1];
    
    int i = 0, j = 0, k = start;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) 
            arr[k++] = left[i++];
        else    
            arr[k++] = right[j++];
    }
    // copy the remaining elements
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
}

// recursive function for merge sort
void mergeSort(int *arr, int start, int end) {
    // base case
    if(start >= end)
        return;
    
    int mid = start + (end - start) / 2;
    // recursive calls
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    // merge the 2 sorted halves
    merge(arr, start, mid, end);
}

// helper function to print the array
void printArray(int *arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}