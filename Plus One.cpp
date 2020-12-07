// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        reverse(d.begin(), d.end());
        int i=1, n=d.size(), carry;
        d[0]+=1;
        carry=d[0]/10;
        d[0]%=10;
        while(i<n && carry>0){
            d[i]+=carry;
            carry=d[i]/10;
            d[i]%=10;
            i++;
        }
        if(carry>0) d.push_back(carry);
        reverse(d.begin(), d.end());
        return d;
    }
};