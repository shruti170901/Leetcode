class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++){
            p[i]=nums[i-1]+p[i-1];
        }
        for(int i=1;i<=n;i++){
            if(p[i-1]==(p[n]-p[i])){
                return i-1;
            }
        }
        return -1;
    }
};
