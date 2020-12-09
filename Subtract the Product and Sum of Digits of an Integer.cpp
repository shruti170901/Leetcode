// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1, sum=0;
        while(n){
            prod*=n%10;
            sum+=n%10;
            n/=10;
        }
        return prod-sum;
    }
};