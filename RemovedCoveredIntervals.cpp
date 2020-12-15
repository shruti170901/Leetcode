class Solution {
public:
    static bool compare(vector<int> &v,vector<int> &t){
        if(v[0]!=t[0])
            return v[0]<t[0];
        return v[1]>=t[1];
        
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        for(int i=0;i<intervals.size();i++){
            for(int j=0;j<intervals[i].size();j++)
                cout<<intervals[i][j]<<" ";
            cout<<"\n";
        }
        int cnt=intervals.size();
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][0]<=intervals[i+1][0]&&intervals[i][1]>=intervals[i+1][1]){
                cnt--;
                intervals[i+1][1]=intervals[i][1];
                intervals[i+1][0]=intervals[i][0];
        
            }
        }
        return cnt;
    }
};