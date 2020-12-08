class Solution {
  
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(1, 1);
        int len = primes.size();
        vector<int> pos(len, 0);
        
        while( ugly.size() < n ) {
            int next = INT_MAX;
            for(int i=0; i<len; i++) {
                next = min(next, ugly[pos[i]] * primes[i]);
            }
            for(int i=0; i<len; i++) {
                if (next == ugly[pos[i]] * primes[i]) {
                    pos[i]++;
                }
            }
            ugly.push_back(next);
        }
        return ugly.back();
    }
    

};
