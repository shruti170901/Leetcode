class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        map<char, int> m {{'(', 1}, {')', -1}, {'[', 2}, {']', -2}, {'{', 3}, {'}', -3}};
        for(int i=0;i<s.size();i++){
            if(m[s[i]]>0) stk.push(m[s[i]]);
            else{
                if(stk.empty()) return false;
                int temp=stk.top();
                if(temp+m[s[i]]==0) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};