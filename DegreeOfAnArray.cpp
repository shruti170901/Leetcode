class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> freq(50000, 0);
      int max_ = 0;
      for (const int n : nums)
         max_ = max(max_, ++freq[n]);
      fill(freq.begin(), freq.end(), 0);
      int min_ = nums.size();
      for (int i = 0, j = -1, size = nums.size(); j < size;) {
         if (j >= 0 && freq[nums[j]] == max_)
            min_ = min(min_, j - i + 1), --freq[nums[i++]];
         else if (j < size - 1)
            ++freq[nums[++j]];
         else
         break;
      }
      return min_;
        
    }
};