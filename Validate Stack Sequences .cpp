class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pos=0;
        for(int i=0; i<pushed.size(); i++){
            st.push(pushed[i]);
            while(st.size() && pos<popped.size() && st.top()==popped[pos]){
                st.pop();
                pos++;
            }
        }
        
        
        return (st.empty()&&pos==popped.size());
    }
};