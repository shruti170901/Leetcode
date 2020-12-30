// https://leetcode.com/problems/stone-game-vi/
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int, int>> stones;
        
        for (int i = 0; i < aliceValues.size(); ++i) {
            stones.push_back({aliceValues[i] + bobValues[i], i});
        }
        
        sort(stones.rbegin(), stones.rend());
        
        int a = 0;
        int b = 0;
        
        for (int i = 0; i < stones.size(); ++i) {
            if (i % 2 == 0) {
                a += aliceValues[stones[i].second];
            } else {
                b += bobValues[stones[i].second];
            }
        }
        
        return a == b ? 0 : a > b ? 1 : -1;
    }
};
