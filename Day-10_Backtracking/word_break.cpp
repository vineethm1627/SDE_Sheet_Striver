/*
    Problem Link: https://practice.geeksforgeeks.org/problems/word-break1352/1#
*/

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// s : given string to search
// dict : vector of available strings

int solve(string s, vector<string> &dict, unordered_map<string, int> &dp) {
    // base case
    if(s.empty())
        return 1;
    // value is pre-computed: memoization
    if(dp[s] != 0)
        return dp[s];
    int size = s.size();
    // recursive calls on all possible substrings of s
    for(int i = 1; i <= size; i++) {
        bool found = false;
        string ss = s.substr(0, i); // substring of size i
        // now search this substring in the dictionary
        for(string &d : dict) {
            if(ss.compare(d) == 0) {
                found = true;
                break;
            }
        } 
        // recursive call on the remaining substring
        if(found == 1 && solve(s.substr(i, size - i), dict, dp) == 1)
            return dp[s] = 1;
    }
    return dp[s] = 0;
}

int wordBreak(string s, vector<string> &dict) {
    //code here
    unordered_map<string, int> dp;
    // dp[string] = 1; if string is present in the dictionary
    // by default dp[string] = 0;
    return solve(s, dict, dp) == 1 ? 1 : 0;
}