/*
    Problem Link: https://leetcode.com/problems/powx-n/
*/

#define lli long long int
lli M = 1e9 + 7;

long long int binary_expo(long long base, long long p) {
    if(p == 0)
        return 1;
    
    if(p < 0) 
        return 1 / binary_expo(base, -p);

    long long int result = 1;
    base %= M;
    
    while(p) {
        if(p & 1) 
            result = result * base % M;
        base = base * base % M;
        p >>= 1;
    }
    return result;
}