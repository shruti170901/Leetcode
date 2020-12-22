class Solution {
public:
    bool isPowerOfThree(int n) {
        int x=0;
        while (n % 3 == 0) {
            if(n==0)
                break;
            n /= 3;
        }
        return n == 1;
    }
};
