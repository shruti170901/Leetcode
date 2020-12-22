class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ones;
        ones.push_back(0);
        ones.push_back(1);
        int count = 2;
        while(count<=num){
            for (int i = 0; i < count; ++i)
            {
            	ones.push_back(ones[i]+1);
            }
            count += count;
        }
        ones.resize(num+1);
        return ones;
    }
};