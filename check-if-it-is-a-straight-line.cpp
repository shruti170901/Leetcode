class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& p) { 
        if(p.size()==2)return true;
        for ( int i=2; i<p.size(); i++ ){
            if(((p[i][1]-p[0][1])*(p[1][0]-p[0][0]))!=((p[1][1]-p[0][1])*(p[i][0]-p[0][0])))return false;
        }return true;
    }
};
