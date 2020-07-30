class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(),ptr=0;
        vector<vector<int>> ans(int(pow(2, n)));
        for(int i = 0; i < int(pow(2, n)); i++) { 
            for(int j = 0; j < n; j++)
                if(i & (1 << j)) 
                    ans[ptr].push_back(nums[j]); 
            ptr++;
        } 
        sort(ans.begin(), ans.end() );
        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
        return ans;
    }
};
