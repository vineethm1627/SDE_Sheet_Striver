/*
    Problem Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/

// helper function to sort array in ascending order of finishing time
    static bool compare(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        // create a pair of starting, finishing time
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++)
            arr[i] = make_pair(start[i], end[i]);
        
        // sort it in ascending order of finishing time: we want to complete activities which end at the earliest
        sort(arr.begin(), arr.end(), compare);
        
        int count = 1; // pick the first activity
        int ft = arr[0].second; // finishing time of first activity
        
        for(int i = 1; i < n; i++) {
            // take current activity if its starting time > finishing time of earlier chosen activity
            if(arr[i].first > ft) {
                count++;
                ft = arr[i].second;
            }
        }
        return count;
    }