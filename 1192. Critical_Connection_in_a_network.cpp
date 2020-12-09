class Solution {
public:
    vector<vector<int>> ans;
    vector<int> parent,id,low;
    int t;
    void dfs(vector<int> adj[],int v){
        id[v]=low[v]=t++;
        for(auto x:adj[v]){
            if(parent[v]!=x){
            if(id[x]==-1){
                parent[x]=v;
                dfs(adj,x);
                low[v]=min(low[v],low[x]);
                if(low[x]>id[v]){
                    ans.push_back({v,x});
                }
            }
            else 
                low[v]=min(low[v],low[x]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        t=0;
        vector<int> adj[n];
        for(auto x:con){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        ans.clear();
        parent.assign(n,-1);
        id.assign(n,-1);
        low.assign(n,-1);
        for(int i=0;i<n;i++){
            if(id[i]==-1){
                dfs(adj,i);
            }
        }
        return ans;
    }
};
