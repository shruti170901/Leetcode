class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *max_element(weights.begin(), weights.end()), r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (possibleToDeliver(weights, D, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool possibleToDeliver(vector<int>& weights, int D, int weight_limit) {
        int cur = 0, days_used = 0;
        for (int w : weights) {
            if (cur + w > weight_limit) {
                cur = 0;
                days_used ++;
            }
            cur += w;
        }
        return days_used + 1 <= D;
    }
};
