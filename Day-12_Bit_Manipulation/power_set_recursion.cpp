/*
    Problem Link: https://practice.geeksforgeeks.org/problems/power-set4302/1#
*/

void generateSubstrings(string s, vector<string> &results, int idx = 0, string ans = "") {
    // base case
    if(idx == s.size()) {
        // don't include empty substring
        if(ans != "")
            results.push_back(ans);
        return;
    }
    // recursive calls:
    // exclude the current element
    generateSubstrings(s, results, idx + 1, ans);
    // include the current element
    generateSubstrings(s, results, idx + 1, ans + s[idx]);
}


vector<string> AllPossibleStrings(string s){
    // Code here
    vector<string> results;
    generateSubstrings(s, results);
    sort(results.begin(), results.end());
    return results;
}