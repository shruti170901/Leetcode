class Solution {
public:
    int numSub(string nums) {
        int n=nums.length();
        long long int count=1;
        if(nums[0]=='0')count=0;
        long long int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]=='1') count++;
            else{
                ans+=((count*(count+1)/2));
                count=0;
            }
        }
        ans+=((count*(count+1)/2));
        return ans%(1000000007);
    }
};
