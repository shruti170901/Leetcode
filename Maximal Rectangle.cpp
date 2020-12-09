// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    void check(vector<int> &v, int &mx){
        int i=0, j, h;
        stack<int> idx;
        while(i<v.size()){
            if(idx.empty() || v[i]>v[idx.top()]) idx.push(i++);
            else{
                h=v[idx.top()];
                idx.pop();
                j=idx.empty()?-1:idx.top();
                mx=max(mx, h*(i-j-1));
            }
        }
        return;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int i, j, n=mat.size(), m;
        if(n==0) return 0;
        m=mat[0].size();
        vector<vector<int>> cpy(n, vector<int>(m+1));
        for(i=0;i<m;i++) cpy[0][i]=mat[0][i]-'0';
        for(i=1;i<n;i++){
            for(j=0;j<m;j++){
                cpy[i][j]=mat[i][j]-'0';
                if(mat[i][j]!='0') cpy[i][j]+=cpy[i-1][j];
            }
        }
        int ans=0;
        for(i=0;i<n;i++){
            check(cpy[i], ans);
        }
        return ans;
    }
};