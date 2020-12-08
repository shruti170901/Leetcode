// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<string> stk;
        int i, n=v.size();
        for(i=0;i<n;i++){
            if(v[i]=="+" || v[i]=="-" || v[i]=="*" || v[i]=="/"){
                int t1=stoi(stk.top()), t2;
                stk.pop();
                t2=stoi(stk.top()); stk.pop();
                if(v[i]=="+"){
                    t2+=t1;
                }
                else if(v[i]=="-"){
                    t2-=t1;
                }
                else if(v[i]=="*"){
                    t2*=t1;
                }
                else{
                    t2/=t1;
                }
                stk.push(to_string(t2));
            }
            else{
                stk.push(v[i]);
            }
        }
        return stoi(stk.top());
    }
};