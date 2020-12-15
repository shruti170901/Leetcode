class Solution {
public:
    vector<vector<int>>ans;
    vector<int>adj[20];
    int n;
    void dfs(int x,vector<int>  d){
        if(x==n-1){
            d.push_back(x);
            ans.push_back(d);
            return;
        }
        d.push_back(x);
        for(auto it=adj[x].begin();it!=adj[x].end();it++){
            dfs(*it,d);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        
        vector<int>d;
        n=graph.size();
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        dfs(0,d);
        
        return ans;
    }
};