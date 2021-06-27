/*
    Problem Link: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
    Calculate square of a number without using *, / and pow()
*/

#include <iostream>
using namespace std;
/*
    If n is even, it can be written as
    n = 2*x 
    n2 = (2*x)^2 = 4*x^2
    If n is odd, it can be written as 
    n = 2*x + 1
    n2 = (2*x + 1)^2 = 4*x^2 + 4*x + 1
*/
int square(int n) {
    // base case
    if(n == 0)
        return 0;
    
    // negative numbers
    if(n < 0)
        n = -n;
    
    // get floor(n / 2) using right shift operator
    int x = n >> 1;

    // recursive calls:
    // case-1: n is odd
    if(n & 1)
        return ((square(x) << 2) + (x << 2) + 1);
    // case-2: n is even
    else
        return (square(x) << 2);

    /*
        x << 2 is same as x * 4
    */
}

int main() {

    int n;
    cin >> n;

    cout << square(n);

    return 0;
}