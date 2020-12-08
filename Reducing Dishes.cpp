// https://leetcode.com/problems/reducing-dishes/

class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int i, j, mx=0, sum, n=s.size();
        sort(s.begin(), s.end());
        for(i=0;i<n;i++){
            sum=0;
            for(j=i;j<n;j++){
                sum+=s[j]*(j-i+1);
            }
            mx=max(mx, sum);
        }
        return mx;
    }
};