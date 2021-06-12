/*
    Problem Link: https://leetcode.com/problems/permutation-sequence/
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        // compute (n-1)! --> permutations when the first number is fixed
        for(int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string result = "";
        k--; // to convert into 0 based indexing
        while(true) {
            result = result + to_string(numbers[k/ fact]);
            // remove this number
            numbers.erase(numbers.begin() + k / fact);
            // if all the numbers are used
            if(numbers.empty())
                break;
            
            // update k and fact
            k = k % fact;
            fact = fact / numbers.size();
        }
        return result;
    }
};