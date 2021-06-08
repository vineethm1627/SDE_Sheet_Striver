/*
    Problem Link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
*/

    // helper function to sort the array in descending order of profit
    static bool compare(Job &a, Job &b) {
        return a.profit > b.profit;
    }
    
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        // your code here
        // sort in descending order of profit
        sort(arr, arr + n, compare);
        int result[n]; // store the index of the job
        int slot[n] = {0}; // deadline based free slots
        // for a job with deadline 3, it can only be stored at index 0,1,2 ie. upto deadline - 1
        
        for(int i = 0; i < n; i++) {
            // find a free slot to accomodate this job
            for(int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
                // free slot is found
                if(slot[j] == 0) {
                    result[j] = i; // store the job index in the sorted array
                    slot[j] = 1; // indicates slot is occupied
                    break;
                }
            }
        }
        int jobs = 0, profit = 0;
        for(int i = 0; i < n; i++) {
            if(slot[i] == 1) {
                // the job is taken into account ie. finished before deadline
                jobs++; // increment number of jobs
                profit += arr[result[i]].profit;
            }
        }
        return {jobs, profit};
    } 
};