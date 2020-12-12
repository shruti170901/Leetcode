class Solution {
    vector<int> dp={1,1};
    
public:
    void genfib(int k){
        int i = 2;
        int next = 1;
        while(1){
            next = dp[i-1] + dp[i-2];
            if(next>k)
                return;
            dp.push_back(next);
            i++;
        }
    }
    int findMinFibonacciNumbers(int k) {
        genfib(k);
        int i = dp.size()-1;
        int ans = 0;
        while(k>0){
            ans += (k/dp[i]);
            k %= dp[i];
            i--;
        }
        return ans;
    }   
};
