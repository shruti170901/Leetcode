class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string temp, ans=strs[0];
        for(int i=1;i<strs.size();i++){
            int j=0;
            temp="";
            while(j<min(ans.size(), strs[i].size()) && ans[j]==strs[i][j]){
                temp+=ans[j];
                j++;
            }
            ans=temp;
        }
        return ans;
    }
};