class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int N = costs.size()/2;
        int num = costs.size();
        int ans = 0, j;
        
        vector< pair <int,int> > vect;
        for (int i = 0; i < num; i++) 
            vect.push_back( make_pair(costs[i][0] - costs[i][1], i)); 
        sort(vect.begin(), vect.end());
        
        for(int i = 0; i < N; i++){
            j = vect[i].second;
            ans += costs[j][0];
        }
        
        for(int i = N; i < num; i++){
            j = vect[i].second;
            ans += costs[j][1];
        }
        
        return ans;
    }
};
