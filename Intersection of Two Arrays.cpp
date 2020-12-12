class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       // 1, 2
        set<int> st;
        vector<int> result;
        for (auto& it : nums1) { //for (int i = 0; i < nums1.size(); i++) <- nums1[i]
            st.insert(it); 
        }
        for (auto& it : nums2) { //set {1, 2}
            if (st.find(it) != st.end()) {
                st.erase(it);
                result.push_back(it); //{2}
            }
        }
        
        return result;
    }
};