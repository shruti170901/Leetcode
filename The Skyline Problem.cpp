class Solution {
public:

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector< pair<int, int> > edges;

        int left, right, height;
        for(int i=0; i<buildings.size(); i++) {
            left   = buildings[i][0];
            right  = buildings[i][1];
            height = buildings[i][2];
            edges.push_back(make_pair(left, -height));
            edges.push_back(make_pair(right, height));
        }
        sort(edges.begin(), edges.end());
        vector< pair<int, int> > result;
        multiset<int> m;
        m.insert(0);
        int pre = 0, cur = 0;
        for (int i=0; i<edges.size(); i++){
            pair<int,int> &e = edges[i];
            if (e.second < 0) {
                m.insert(-e.second);
            }else{
                m.erase(m.find(e.second));
            }
            cur = *m.rbegin();
            if (cur != pre) {
                result.push_back(make_pair(e.first, cur));
                pre = cur;
            }
        }
        return result;

    }
};
