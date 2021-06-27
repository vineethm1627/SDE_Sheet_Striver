/*
    Problem Link: https://practice.geeksforgeeks.org/problems/power-set4302/1#
*/

vector<string> AllPossibleStrings(string s){
    // Code here
    vector<string> results;
    int n = (int)s.size();
    // go through binary representation from 1 to 2^n
    for(int i = 1; i < (1 << n); i++) {
        string res = "";
        int temp = i, j = 0;
        while(temp) {
            if(temp & 1) 
                res += s[j];
            j++;
            temp >>= 1;
        }
        // don't include the empty substring
        if(!res.empty())
            results.push_back(res);
    }
    // lexographic order of results
    sort(results.begin(), results.end());
    return results;
}