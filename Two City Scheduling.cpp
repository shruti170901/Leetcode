
class Solution {
private:
    static int diff(vector<int>& x) {
        return x[1] - x[0];
    }
    static bool cmpfunc(vector<int>& lhs, vector<int>& rhs) {
        return diff(lhs) > diff(rhs);
    }

public:
    // Just simply sort the array by comparing the different cost go to A city and B city
    // then the bigger difference would be in left and right side, and the smaller difference would be in the middle
    // We could simply let the first half go to A city, and the second half go to B city.
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmpfunc);
        int result = 0;
        int len = costs.size();
        for (int i=0; i<len/2; i++) {
            result += (costs[i][0] + costs[len-i-1][1]);
        }
        return result;
    }
};
