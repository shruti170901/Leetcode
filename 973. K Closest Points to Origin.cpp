class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> h;
        for(int i=0;i<points.size();i++){
            h.push(make_pair(points[i][0]*points[i][0]+points[i][1]*points[i][1],i));
            if(h.size()>k){
                h.pop();
            }
        }
        int i;
        while(h.size()>0){
            i=(h.top()).second;
            ans.push_back(points[i]);
            h.pop();
        }
        return ans;
    }
};
