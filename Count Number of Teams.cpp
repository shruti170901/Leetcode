// https://leetcode.com/problems/count-number-of-teams/

class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans=0;
        for(int i=0;i<r.size();i++){
            for(int j=i+1;j<r.size();j++){
                for(int k=j+1;k<r.size();k++){
                    if((r[i]>r[j] && r[j]>r[k]) || (r[i]<r[j] && r[j]<r[k])) ans++;
                }
            }
        }
        return ans;
    }
};