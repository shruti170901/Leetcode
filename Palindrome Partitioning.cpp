// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPal(string &s){
        if(s.size()<=1) return true;
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    void rec(string& s, int idx, vector<vector<string>>&ans, vector<string>&temp){
        if(idx>=s.size()){
            ans.push_back(temp);
            return;
        }
        int i;
        string pal="";
        for(i=idx;i<s.size();i++){
            pal+=s[i];
            if(isPal(pal)){
                //cout<<pal<<endl;
                //if(i+1==s.size()){}
                temp.push_back(pal);
                rec(s, i+1, ans, temp);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        rec(s, 0, ans, temp);
        return ans;
    }
};