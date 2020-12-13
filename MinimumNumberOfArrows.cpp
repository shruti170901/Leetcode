class Solution {
public:
    static bool compare(vector<int>&x,vector<int>&y){
        return x[1]<y[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        if(points.size()==1)
            return 1;
        sort(points.begin(),points.end(),compare);
        int cnt=1;
        int prev=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]>prev){
                cnt++;
                prev=points[i][1];
                 
            }
           
        }
        return cnt;
        
    }
};