// 1443. Minimum Time to Collect All Apples in a Tree
//https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        std::vector<std::vector<int>> adj(n);
        std::vector<bool> visited(n, false);
        for(const auto &e: edges) adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
        auto [s, _]{dfs(0, adj, visited, hasApple)};
        return s;
    }
    
    static std::pair<int,bool> dfs(int i, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, std::vector<bool>& hasApple) {
        int sum{0};
        bool apple{hasApple[i]};
        visited[i] = true;
        for(const auto &n: adj[i]) {
            if(visited[n]) continue;
            auto [s, a]{dfs(n, adj, visited, hasApple)};
            apple |= a;
            if(a) sum += 2+s;
        }
        return {sum, apple};
    }
};
