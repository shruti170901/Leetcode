class Solution {
private:
    string get_award(int i) {
        // get award string according for the i^th place
        if (i == 0) return "Gold Medal";
        else if (i == 1) return "Silver Medal";
        else if (i == 2) return "Bronze Medal";
        else return to_string(i+1);
    }
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        const int N = nums.size();
        vector<string> rst;        
        if (not nums.empty()) {
            // sort index according to nums
            vector<int> idx(N);
            iota(idx.begin(), idx.end(), 0);
            sort(idx.begin(), idx.end(), [&](int j, int k) {
                return nums[j] > nums[k];
            });
            // construct rst
            rst.resize(N);
            for (int i(0); i < N; ++i) {
                 rst[idx[i]] = get_award(i);
            }
        }
        return rst;
    }
};
