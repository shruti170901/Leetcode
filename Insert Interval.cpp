// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& newInterval) {
        A.push_back(newInterval);
        vector<vector<int>> ans;
        sort(A.begin(), A.end());
        for(vector<int> it:A){
            if(ans.size()==0) ans.push_back(it);
            else{
                if(it[0]<=ans[ans.size()-1][1]) ans[ans.size()-1][1]=max(ans[ans.size()-1][1], it[1]);
                else ans.push_back(it);
            }
        }
        return ans;
    }
};