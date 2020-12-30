class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        while(start<=end){
            int mid =start+(end-start)/2;
            
            if(mid!=0&&mid!=nums.size()-1&&nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid==0&&nums[mid+1]!=nums[mid]){
                return nums[mid];
            }
            if(mid==nums.size()-1&&nums[mid-1]!=nums[mid]){
                return nums[mid];
            }
            if(mid!=0&&nums[mid]==nums[mid-1]){
                if((end-mid)%2==0){
                    end=mid-2;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if((mid-start)%2==0){
                    start=mid+2;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};
