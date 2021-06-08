/*
    Problem Link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/

struct Item {
    int value;
    int weight;
};

class Solution
{
    public:
    // custom compare function based on higher ratio of value/weight.
    static bool compare(Item &a, Item &b) {
        return ((double)a.value / a.weight) > ((double)b.value / b.weight);
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Your code here
        sort(arr, arr + n, compare);
        
        int cur_w = 0;
        double max_val = 0;
        
        for(int i = 0; i < n; i++) {
            // current weight could be accomodated fully
            if(cur_w + arr[i].weight <= W) {
                cur_w += arr[i].weight;
                max_val += arr[i].value;
            }
            else {
                // add fraction of the weight value
                int remaining_w = W - cur_w;
                max_val += arr[i].value * ((double)remaining_w / arr[i].weight);
                break;
            }
        }
        return max_val;
    }
        
};