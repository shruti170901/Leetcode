// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i, l, r, n=nums.size();
        if(n<=1) return;
        l=0; r=n-1;
        i=0;
        while(i<n){
            //cout<<i<<endl;
            if(nums[i]==0){
                if(i>l){
                    swap(nums[i], nums[l]);
                    l++;
                }
                else{
                    if(i==l)l++;
                    i++;
                }
            }
            else if(nums[i]==2){
                if(i<r){
                    swap(nums[i], nums[r]);
                    r--;
                }
                else{
                    i++;
                }
            }
            else i++;
        }
        return;
    }
};