/*
    Problem Link: https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
*/

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    /*
        recursive solution
        x*2^(x-1) --> total set bits in group (nearest power of 2)
        for the above group MSB will be 0
        for the remaining numbers not part of the group: MSB will be 1
        count of those MSB bits = n - 2^x + 1
        now we need to count set bits in the remaining numbers after removing their MSB
        
        // recursive function: f(n) = x*2^(x-1) + (n - 2^x + 1) + f(n - 2^x)
        
        Note:
            2^x = (1 << x)
    */
    
    // helper function to find the greatest power of 2 <= n
    int largestPowerOf2(int n) {
        int x = 0;
        while((1 << x) <= n) 
            x++;
        
        return x - 1;
    }

    int countSetBits(int n) {
        // edge case
        if(n == 0)
            return 0;

        int x = largestPowerOf2(n);
        int bitsInGroup = x * (1 << (x - 1));
        int msb_rem = n - (1 << x) + 1;
        int smaller_prob = n - (1 << x);

        return bitsInGroup + msb_rem + countSetBits(smaller_prob);
    }
};