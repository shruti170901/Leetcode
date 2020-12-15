class Solution{
public:
 vector<vector<int>>w;
    void paths(vector<vector<int>>& graph,int s,int d, vector<int>&v,vector<bool>&isdone){
        if(s==d){
           w.push_back(v);
            return;
        }
         isdone[s]=true;
        for(int i=0;i<graph[s].size();i++){
            if(!isdone[graph[s][i]]){
                v.push_back(graph[s][i]);
                paths(graph,graph[s][i],d,v,isdone);
                v.pop_back();
               }
        }
        isdone[s]=false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size()==0){
              vector<vector<int>>x;
            return x;
        }
         vector<int>v;
        int n=graph.size();
        v.push_back(0);
        vector<bool>isdone(n,false);
        paths(graph,0,n-1,v,isdone);
        return w;
    }
};
