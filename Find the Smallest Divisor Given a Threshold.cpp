class Solution {
public:
    bool satisfy(vector<int>&nums,int threshold,int mid){
        int sum=0;
        for(auto x:nums){
            if(x%mid!=0)
            sum+=(x/mid+1);
            else
                sum+=x/mid;
        }
        if(threshold>=sum){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxn=-1,minn=INT_MAX;
        for(auto x: nums){
            maxn=max(maxn,x);
            minn=min(minn,x);
        }
        int start=1,end=maxn;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(satisfy(nums,threshold,mid)){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }   
};
