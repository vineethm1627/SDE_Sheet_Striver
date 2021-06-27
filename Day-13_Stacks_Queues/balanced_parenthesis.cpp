/*
    Problem Link: https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        // for every opening bracket push the corresponding closing bracket
        for(const char &ch : str) {
            switch(ch) {
                case '(':
                    s.push(')');
                    break;
                case '{':
                    s.push('}');
                    break;
                case '[':
                    s.push(']');
                    break;
                default:
                    // closing bracket is encountered
                    // no opening bracket exists
                    if(s.empty())
                        return false;
                    // matching bracket is found: pop it and continue
                    else if(ch == s.top()) 
                        s.pop();
                    else
                        return false;
                    break;       
            }
        }
        // some extra brackets could have been left out
        // for valid parenthesis, stack must be empty
        return s.empty();
    }
};