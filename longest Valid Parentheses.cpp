class Solution {
public:
    int longestValidParentheses(string s){
        if(s.size() == 0) return 0;
        stack<char> st;
        stack<int> idx;
        int len = INT_MIN;
        idx.push(-1); 
        for(int i = 0;i<s.size();i++){
        	if(s[i] == '('){
        		st.push('(');
        		idx.push(i);
            }
        	else if(s[i] == ')'){
        		if(!st.empty() && st.top() == '('){
        			idx.pop();
        			st.pop();
        			len = max(len,i - idx.top());
        		}
        		else idx.push(i); 
        	}
        }if(len == INT_MIN) 
            return 0;
        return len;
    }
};
