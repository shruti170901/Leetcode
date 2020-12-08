class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pos(primes.size(), 0);
        vector<int> num(n, 0);
        num[0]=1;       
        for(int i=1; i<n; i++){
            num[i]= primes[0]*num[pos[0]];
            for(int j=0; j<primes.size(); j++){
                num[i]= min(num[i], primes[j]*num[pos[j]]);
            }
            for(int j=0; j<primes.size(); j++){
                if(num[i]==primes[j]*num[pos[j]]){
                    pos[j]++;
                }
            }
            
        }
        
        cout<<n;
        return num[n-1];
    }

};