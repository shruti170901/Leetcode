class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==1)
            return cost[0];
        int c[n];
        for(int i=0;i<n;i++){
            c[i]=0;
        }
        c[0]=cost[0];
        c[1]=cost[1];
        for(int i=2;i<n;i++){
            c[i]=cost[i]+min(c[i-1],c[i-2]);
        }
        return min(c[n-1],c[n-2]);
    }
};
