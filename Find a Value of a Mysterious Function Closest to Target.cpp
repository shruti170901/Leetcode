class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int best = 1e9;
        int tot = arr[0];
        for(int i = 0; i < arr.size(); i++) {
            best = min<int>(best, abs(target-arr[i]));
            tot &= arr[i];
            best = min<int>(best, abs(target-tot));
        }
        
        return best;
    }
};
