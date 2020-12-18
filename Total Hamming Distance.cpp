class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long long solution = 0;
        int ones[31];
        for(int i = 0; i < 31; i++)
            ones[i] = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            for(int i = 0; (1 << i) <= *it; i++) //i is the position of the bit
                if((1 << i) & *it)//to see if the bit at i-position is a 1
                    ones[i]++;
        }
        for(int i = 0; i < 31; i++)
            solution += ones[i] * (nums.size() - ones[i]);
        return solution;
    }
};
