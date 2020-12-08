// https://leetcode.com/problems/battleships-in-a-board/

class Solution {
public:
    int countBattleships(vector<vector<char>>& b) {
        int i, j, m=b.size(), n=b[0].size(), ans=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(b[i][j]=='X') ans++;
                if(i>0 && b[i-1][j]=='X' && b[i][j]=='X') ans--;
                if(j>0 && b[i][j-1]=='X' && b[i][j]=='X') ans--;
                //cout<<ans<<endl;
            }
        }
        return ans;
    }
};