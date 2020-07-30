class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& temp1, vector<int>& temp2){
            if(temp1[0] != temp2[0]) return temp1[0] > temp2[0];
            else return temp1[1] < temp2[1];
        });
        
        vector<vector<int>> new_p;
        for(auto itr : people){
            new_p.emplace(new_p.begin() + itr[1], itr);
        }
        return new_p;
    }
};
