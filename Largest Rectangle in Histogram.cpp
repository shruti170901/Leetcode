// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<pair<int, int>> stk;
        int i, n=h.size();
        vector<int> l(n), r(n);
        //l[0]=-1;
        //r[n-1]=n;
        for(i=0;i<n;i++){
            while(!stk.empty() && h[i]<=stk.top().first){
                stk.pop();
            }
            if(stk.empty()){
                l[i]=-1;
            }
            else{
                l[i]=stk.top().second;
            }
            stk.push({h[i], i});
        }
        while(!stk.empty()) stk.pop();
        for(i=n-1;i>=0;i--){
            while(!stk.empty() && h[i]<=stk.top().first){
                stk.pop();
            }
            if(stk.empty()){
                r[i]=n;
            }
            else{
                r[i]=stk.top().second;
            }
            stk.push({h[i], i});
        }
        //for(i=0;i<n;i++) cout<<l[i]<<" "<<r[i]<<endl;
        int mx=0;
        for(i=0;i<n;i++){
            mx=max(mx, h[i]*(r[i]-l[i]-1));
        }
        return mx;
    }
};