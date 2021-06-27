/*
    Problem Link: https://practice.geeksforgeeks.org/problems/power-set4302/1#
*/

vector<string> generateSubstrings(string s) {
    // base case: empty substring when no char is selected
    if(s.empty())
        return {""}; // vector of size 1 having empty string
    
    // extract the first char
    char ch = s[0];
    // get the remaining string
    string rem_s = s.substr(1);
    // recursive calls
    vector<string> results = generateSubstrings(rem_s);
    vector<string> my_results;
    // first char is not included
    for(string &str : results)
        my_results.push_back("" + str);
    // first char is included
    for(string &str : results)
        my_results.push_back(ch + str);
    
    return my_results;
}

vector<string> AllPossibleStrings(string s) {
    // Code here
    vector<string> results = generateSubstrings(s);
    results.erase(results.begin()); // remove the empty substring from power set
    sort(results.begin(), results.end());
    
    return results;
}