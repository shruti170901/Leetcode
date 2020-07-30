class Solution {
public:
    int numWaterBottles(int n, int k) {
        return (k*((n-1)/(k-1)) + 1 + (n-1)%(k-1));
    }
};
