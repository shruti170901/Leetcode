class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>& n=nums;
        sort(n.begin(),n.end());
        int t=n.size();
        for(int i=0;i<t-1;i++){
            if(n[i]==n[i+1])return n[i];
        }
        return 0;
    }
};
