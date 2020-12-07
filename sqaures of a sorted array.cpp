class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i;
        vector<int> A(nums.size(),0);
        for(i=0 ; i <nums.size();i++){
            A[i]= nums[i]*nums[i];
        }
        sort(A.begin(),A.end());

        return A;
    }
};
