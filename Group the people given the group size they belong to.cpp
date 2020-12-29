// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        vector<pair<int, int>> group;
        for(int i=0;i<groupSizes.size();i++){
            group.push_back(make_pair(groupSizes[i], i));
        }
        sort(group.begin(), group.end());
        int i, j;
        for(i=0;i<group.size();i=j){
            vector<int> v;
            for(j=i;j<i+group[i].first;j++){
                v.push_back(group[j].second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};