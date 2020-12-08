class Solution {
public:
    void swap(int& i,int& j){
        int temp=i;
        i=j;
        j=temp;
    }
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
        int i=0,j=1;
        while(i<size-1&&j<size){
            if(nums[i]!=0 && nums[j]!=0){
                i++;j++;
                continue;
            }
        if(nums[i]==0)
        {
            if(nums[j]==0)
                j++;
            else{
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            
        }
        else{
            if(nums[j]==0)
            {
                i++;
                j++;
            }
          
        }
    }  
}
};