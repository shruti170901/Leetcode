class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt;
        for(int i=1;i<=n;i++){
            if(k>0 && n%i==0){
                cnt=i;
                k--;
            }
        }
        if(k!=0)cnt=-1;
        return cnt;
    }
};
