class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int a = n-1;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0; i < n and i < a and nums[i] < k; i++){
            int j = a;
            while(j >= 0 and i < j){
                if(nums[j] == (k - nums[i])){
                    cnt++;
                    j--;
                    break;
                }
                else if(nums[j] + nums[i] < k){
                    break;
                }
                j--;
            }
            a = j;
            
        }
        return cnt;
    }
};
