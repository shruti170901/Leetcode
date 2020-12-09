class Solution {
public:
    int fib(int n) { 
        double phi = (1 + sqrt(5)) / 2; 
        return round(pow(phi, n) / sqrt(5)); 
    } 
    int climbStairs(int n) {
         n=fib(n+1);
        return n;
    }
};

