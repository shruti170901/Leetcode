class Solution {
public:
    static constexpr long long MOD = 1000000007;
    bool check(string& s, int len) {
        unordered_map<long long, vector<int>> lookup;
        long long sum = 0, mult = 1;
        for (int i = 0; i < n; ++i) {
            int num = s[i] - 'a';
            sum = (sum * 26 + num) % MOD;
            if (i >= len) {
                sum = (sum - mult * (s[i-len] - 'a')) % MOD;
                while (sum < 0)
                    sum += MOD;
                sum %= MOD;
            } else
                mult = (mult * 26) % MOD;
            auto& vect = lookup[sum];
            int index = i-len+1;
            for (int j: vect) {
                if (s.compare(index, len, s, j, len) == 0) {
                    pos = j, length = len;
                    return true;
                }
            }
            if (i >= len - 1)
                vect.push_back(index);
        }
        return false;
    }

    int n, pos, length;
    string longestDupSubstring(string& s) {
        vector<vector<int>> indexes(26);
        n = s.size();
        length = -1;
        int lo = 1, hi = n-1;
        while (lo <= hi) {
            int mid = (lo+hi) / 2;
            if (check(s, mid))
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return (length >= 0) ? s.substr(pos, length) : "";
    }
};
