// https://leetcode.com/problems/destination-city/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> s;
        int i, n=paths.size();
        for(i=0;i<n;i++){
            s.insert(paths[i][0]);
        }
        for(i=0;i<n;i++){
            if(s.find(paths[i][1])==s.end()) break;
        }
        return paths[i][1];
    }
};