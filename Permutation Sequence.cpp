// https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        int i, fact[10]={0}, temp, j, l;
        fact[0]=1;
        for(i=1;i<10;i++) fact[i]=fact[i-1]*i;
        string ans="";
        vector<int> v(n+1, 1);
        k--;
        i=0;
        while(i<n){
            temp=k/fact[n-1-i];
            j=0;
            for(l=1;l<=9;l++){
                if(v[l]==1){
                    j++;
                    if(j-1==temp) break;
                }
            }
            ans+=char('0'+l);
            v[l]=0;
            k-=temp*fact[n-1-i];
            i++;
        }
        return ans;
    }
};