// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution {
public:
    double average(vector<int>& s) {
        int i, sum=0, n=s.size();
        sort(s.begin(), s.end());
        for(i=1;i<n-1;i++) sum+=s[i];
        return (double)sum/(n-2);
    }
};