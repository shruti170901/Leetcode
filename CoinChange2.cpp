class Solution {
public:
    int change(int amount, vector<int> &coins) {
        sort(coins.begin(), coins.end());
        vector<int> dp(static_cast<unsigned long>(amount + 1));
        dp[0] = 1;
        for (int i : coins) {
            for (int j = i; j <= amount; ++j) {
                dp[j] += dp[j - i];
            }
        }
        return dp[amount];
    }
};
