class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > h;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            h.push({matrix[i][0],{i,0}});
        }
        int cnt=0;
        while(cnt!=k){
            int i=h.top().second.first;
            int j=h.top().second.second;
            j++;
            cnt++;
            if(cnt==k){
                return h.top().first; 
            }                        
            h.pop();

            if(j<n)
            h.push({matrix[i][j],{i,j}});
        }
        return -1;
        
    }
};
