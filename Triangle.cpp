// https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        vector<int> v[2];
        if(tri.size()==0) return 0;
        v[0].push_back(tri[0][0]);
        int flag=0, i, j, n=tri.size(), temp;
        //if(n==1) return tri[0][0];
        for(i=1;i<n;i++){
            v[flag^1].clear();
            for(j=0;j<tri[i].size();j++){
                temp=INT_MAX;
                if(j>0) temp=min(temp, v[flag][j-1]+tri[i][j]);
                if(j<tri[i].size()-1) temp=min(temp, v[flag][j]+tri[i][j]);
                v[flag^1].push_back(temp);
            }
            flag^=1;
        }
        temp=INT_MAX;
        for(i=0;i<v[flag].size();i++) temp=min(temp, v[flag][i]);
        return temp;
    }
};