/*
    Find nth root of a number m upto p decimal places.
*/

#include <iostream>
#include <cmath>
using namespace std;

// multiply num n times
double multiply(double num, int n) {
    double ans = 1.0;
    while(n--) 
        ans *= num;
    
    return ans;
}

void getNthRoot(int n, int m, int p) {
    double start = 1, end = m;
    double eps = pow(10, -p);

    while((end - start) > eps) {
        double mid = start + (end - start) / 2;
        if(multiply(mid, n) < m)
            start = mid;
        else
            end = mid;
    }

    cout << "estimated ans:";
    cout << start << " " << end << endl;
    cout << "actual ans:";
    cout << pow(m, (double)(1.0 / (double)n));
}

int main() {

    int n, m, p;
    cin >> n >> m >> p;

    getNthRoot(n, m, p);

    return 0;
}

