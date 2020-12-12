class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1) return n;
        vector<int> gapSum(nums.size(), 0);
        gapSum[n-1]=nums[n-1];
        gapSum[n-2]=nums[n-2];
        for(int i=n-3; i>=0; i--){
            gapSum[i]=nums[i]+gapSum[i+2];
        }
        
        int ans=0, odd=0, even=0;
        for(int i=0; i<n-1; i++){
            
            int fodd=odd, feven=even;
            if(i%2==0){
                fodd += gapSum[i+1];
                feven += gapSum[i]-nums[i];
                odd += nums[i];
            }else{
                feven += gapSum[i+1];
                fodd += gapSum[i]-nums[i];
                even += nums[i];
            }
            
            ans += (feven==fodd);
        }
        
        if(n%2){
            ans += ((gapSum[0]-nums[n-1])==gapSum[1]);
        }else{
            ans += ((gapSum[0])==(gapSum[1]-nums[n-1]));
        }
        
        return ans;
    }
};