class Solution {
public:
bool cycle_detect_dfs(vector<vector<int>> & adj, vector<int>& state, int node)
{
    state[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (state[adj[node][i]] == 1)  return false;
        if (state[adj[node][i]] == 0)
        {
            if (cycle_detect_dfs(adj, state, adj[node][i]) == false)  return false;
        }
    }
    state[node] = 2;
    return true;
}
bool canFinish(int numCourses, vector<vector<int>> prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> state(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (!state[i])
        {
            if(!cycle_detect_dfs(adj, state, i)) return false;
        }
    }
    return true;
}
};