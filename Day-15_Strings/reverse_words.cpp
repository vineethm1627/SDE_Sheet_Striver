/*
    Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/
*/

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            // leading spaces at the start
            if(word.empty()) {
                while(s[i] == ' ')
                    i++;
            }
            // add the characters to the string word
            if(s[i] != ' ')
                word += s[i];
            // push the words when space is encountered or i == (n - 1), for the last word
            if(s[i] == ' ' || i == n - 1) {
                if(!word.empty())
                    st.push(word);
                // reset string to store the next word
                word.clear();
            }
        }
        word.clear();
        while(!st.empty()) {
            word += st.top();
            st.pop();
            word += " ";
        }
        // remove the last added space 
        word.pop_back();
        return word;
    }
};