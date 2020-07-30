class Solution{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> ans;
        vector<int> tmp;
        f(graph , ans , tmp , 0);
        return ans;
    }

    void f(vector<vector<int>> &graph, vector<vector<int>> &ret, vector<int> tout, int start) {
        tout.push_back(start);
        if (tout.back() == graph.size() - 1) {
            ret.push_back(tout);
            return;
        }
        for (auto it : graph[start]) 
            f(graph, ret, tout, it);
    }
};
