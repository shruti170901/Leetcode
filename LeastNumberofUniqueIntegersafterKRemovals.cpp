class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int mi) {
    int n=arr.size();
    unordered_map<int, int> m; 
    vector<pair<int, int> > v; 
    int count = 0; 
    for (int i = 0; i < n; i++) 
        m[arr[i]]++; 
    for (auto it = m.begin(); it != m.end(); it++) 
        v.push_back(make_pair(it->second, it->first)); 
    sort(v.begin(), v.end()); 
    int size = v.size(); 
    for (int i = 0; i < size; i++) { 
        if (v[i].first <= mi) { 
            mi -= v[i].first; 
            count++; 
        } 
        else
            return size - count; 
    } 
    return size - count; 
} 
};
