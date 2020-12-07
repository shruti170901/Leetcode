// https://leetcode.com/problems/merge-intervals/

bool comp(vector<int>a, vector<int>b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]<b[1];
    }

class Solution {
public:
    
    //bool (Solution::*func)(vector<int>a, vector<int>b);
    //func=&Solution::comp;
    vector<vector<int>> merge(vector<vector<int>> A) {
        vector<vector<int>> ans;
        if(A.size()==0) return ans;
        
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