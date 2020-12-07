// https://leetcode.com/problems/maximum-69-number/

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> v;
        int i, ans=0, t=1;
        while(num){
            v.push_back(num%10);
            num/=10;
        }
        i=v.size()-1;
        while(i>=0 && v[i]==9) i--;
        if(i>=0) v[i]=9;
        i=0;
        while(i<v.size()){
            ans+=v[i]*t;
            i++;
            t*=10;
        }
        return ans;
    }
};