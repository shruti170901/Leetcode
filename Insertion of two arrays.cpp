class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set n1(nums1.begin(),nums1.end());
        set n2(nums2.begin(),nums2.end());
        if(n1.size()<n2.size())
        {
            for(auto c:n1)
            {
                if(n2.count(c))
                res.push_back(c);
            }
        }
        else{
            for(auto c:n2)
            {
                if(n1.count(c))
                res.push_back(c);
            }
        }
        return res;
    }

};