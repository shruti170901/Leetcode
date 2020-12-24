class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n=A.size();
        int pref=0;
        vector<int> m(K);
        m[0]++;
        int cnt=0;
        for(int i=1;i<=n;i++){
            pref+=A[i-1]%K+K;
            pref%=K;
            cnt+=m[pref];
            m[pref]++;
        }
        return cnt;
    }
};
