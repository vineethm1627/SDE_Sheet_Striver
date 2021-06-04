/*
    Problem Link: https://leetcode.com/problems/reverse-pairs/
*/

class Solution {
public:
    // similar to merge sort: count inversions
    
    // helper function to count inversions
    int merge(vector<int> &nums, int start, int mid, int end) {
        int count = 0;
        int n1 = mid - start + 1; // mid is included
        int n2 = end - mid;
        // fill the values
        int left[n1], right[n2];
        
        for(int i = 0; i < n1; i++)
            left[i] = nums[start + i];
        for(int i = 0; i < n2; i++)
            right[i] = nums[mid + i + 1];
        
        // count the required pairs 
        // traverse the left part of the array
        int j = 0;
        for(int i = 0; i < n1; i++) {
            while(j < n2 && left[i] > 2LL * right[j]) 
                j++;
            count += j;
        }
        
        // 3 pointers
        int i = 0, k = start;
        j = 0;
        while(i < n1 && j < n2) {
            if(left[i] <= right[j])
                nums[k++] = left[i++];
            else
                nums[k++] = right[j++];
        }
        // add the remaining elements
        while(i < n1)
            nums[k++] = left[i++];
        while(j < n2)
            nums[k++] = right[j++];
        
        return count;
    }
    
    // recursive mergeSort function
    int mergeSort(vector<int> &nums, int start, int end) {
        // base case
        if(start >= end)
            return 0;
        
        int mid = start + (end - start) / 2;
        int count = mergeSort(nums, start, mid);
        count += mergeSort(nums, mid + 1, end);
        // cross inversions
        count += merge(nums, start, mid, end);
        
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};