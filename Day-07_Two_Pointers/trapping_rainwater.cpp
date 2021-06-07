/*
    Problem Link: https://leetcode.com/problems/trapping-rain-water/
*/

    
int trappingWater(int arr[], int n){
    // calculate the water stored on/ above each block
    // using 2 pointer approach
    int left = 0, right = n - 1;
    int max_left = 0, max_right = 0;
    int total = 0;
    
    while(left <= right) {
        // left one is the min height
        if(arr[left] < arr[right]) {
            // maintain max height from left
            if(arr[left] > max_left)
                max_left = arr[left]; // no water can be stored on this block
            else
                total += (max_left - arr[left]); // max capacity - cur height
            
            left++;
        }
        // right one is the min height
        else {
            // maintain max height from right
            if(arr[right] > max_right)
                max_right = arr[right]; // no water can be stored on this block
            else
                total += (max_right - arr[right]); // max capacity - cur height

            right--;
        }
    }
    return total;
}