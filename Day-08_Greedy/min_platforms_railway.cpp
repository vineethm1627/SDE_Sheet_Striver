/*
    Problem Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
*/

//Function to find the minimum number of platforms required at the
//railway station such that no train waits.
int findPlatform(int arr[], int dep[], int n) {
    // Your code here
    // sort both the arrival and departure times in ascending order
    sort(arr, arr + n);
    sort(dep, dep + n);
    
    int count = 1; // platform needed for the arrival of the first train 
    int max_count = 1;
    // use Two pointer approach
    int i = 1, j = 0;
    
    while(i < n && j < n) {
        // current train arrives before prev train's departure
        if(arr[i] <= dep[j]) {
            count++;
            i++;
        }
        // one platform gets free as current train arrives after the departure of prev train
        else {
            count--;
            j++;
        }
        // update max platforms needed at a particular moment of time
        if(count > max_count)
            max_count = count;
    }
    return max_count;
}
