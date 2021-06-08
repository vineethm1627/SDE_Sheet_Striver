/*
    Problem Link: https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
*/

  // helper function to sort the array in ascending order of ending day
    static bool compare(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
    
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n) {
        // create a pair of starting, ending day
        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++)
            arr[i] = make_pair(start[i], end[i]);
        
        // sort it in ascending order of ending day: we want to complete activity which end at the earliest
        sort(arr.begin(), arr.end(), compare);
        
        int count = 1; // pick the first activity
        int ft = arr[0].second; // finishing time of first activity
        
        for(int i = 1; i < n; i++) {
            // take current activity if its starting time > finishing time of earlier chosen activity
            if(arr[i].first > ft) {
                ft = arr[i].second;
                count++;
            }
        }
        return count;
    }