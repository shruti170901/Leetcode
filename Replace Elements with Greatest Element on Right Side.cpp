// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       int i, n=arr.size(), m, t;
        m=arr[n-1];
        for(i=n-2;i>=0;i--){
            t=arr[i];
            arr[i]=m;
            m=max(m, t);
        }
        arr[n-1]=-1;
        return arr;
    }
};