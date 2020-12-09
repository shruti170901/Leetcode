// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string s) {
        stack<string> stk;
        string temp="";
        int i, n=s.size();
        for(i=0;i<n;i++){
            if(s[i]=='/'){
                if(temp=="..") {if(!stk.empty()) stk.pop();}
                else if(temp!="" && temp!=".") stk.push(temp);
                temp="";
                continue;
            }
            else temp+=s[i];
        }
        //cout<<temp<<endl;
        if(temp=="..") {if(!stk.empty()) stk.pop();}
        else if(temp!="" && temp!=".") stk.push(temp);
        //cout<<stk.top()<<endl;
        string ans="";
        while(!stk.empty()){
            ans="/"+stk.top()+ans;
            stk.pop();
        }
        if(ans=="") return "/";
        return ans;
    }
};