class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int pref=0;
        unordered_map<int,int> m(n+1);
        m[0]++;
        int cnt=0;
        for(int i=0;i<n;i++){
            pref+=nums[i];
            if(m.find(pref-k)!=m.end()){
                cnt+=m[pref-k];
            }
            m[pref]++;
        }
        return cnt;
    }
};
