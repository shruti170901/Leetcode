class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        sort(groupSizes.begin(),groupSizes.end());
        int count=0;
        for(int i=0;i<n;){
            count++;
            i+=groupSizes[i];
        }
        vector<vector<int>> v(count);
        int k=0, m=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<groupSizes[i];j++){
                v[m].push_back(k++);
            }
            m++;
            i+=groupSizes[i]-1;
        }
        return v;
    }
};
