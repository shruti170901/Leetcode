class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int x;
        sort(nums.begin(),nums.end());
        set<int> s(nums.begin(), nums.end());
        if(s.size() >= 3)
            x = *std::next(s.begin(), s.size()-3);
        else
            x = *std::next(s.begin(), s.size()-1);
        return x;
    }

};
