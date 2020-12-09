// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    set<string> rec(int n){
        set<string> a, b, c;
        if(n==1){
            a.insert("()");
            return a;
        }
        b=rec(n-1);
        for(auto it:b){
            a.insert("("+it+")");
        }
        for(int i=1;i<=n/2;i++){
            b=rec(i);
            c=rec(n-i);
            for(string it:b){
                for(string jt:c){
                    a.insert(it+jt);
                    a.insert(jt+it);
                }
            }
        }
        return a;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0) return ans;
        set<string> a=rec(n);
        for(auto it:a) ans.push_back(it);
        return ans;
    }
};