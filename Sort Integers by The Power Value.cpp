// https://leetcode.com/problems/sort-integers-by-the-power-value/

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> s;
        int i, t, a;
        for(i=lo;i<=hi;i++){
            t=i; a=0;
            while(t>1){
                a++;
                if(t%2) t=3*t+1;
                else t/=2;
            }
            s.push_back({a, i});
        }
        sort(s.begin(), s.end());
        return s[k-1].second;
    }
};