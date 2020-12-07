// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int i, j;
        vector<int> v;
        for(i=0;i<p.size();i++){
            j=i+1;
            while(j<p.size()){
                if(p[j]<=p[i]) break;
                j++;
            }
            if(j<p.size()) v.push_back(p[i]-p[j]);
            else v.push_back(p[i]);
        }
        return v;
    }
};