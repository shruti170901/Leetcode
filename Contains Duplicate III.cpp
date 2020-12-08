// https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& v, int k, int t) {
        map<int, int> m;
        int i, j, n=v.size();
        if(v.size()==0) return false;
        if(k==0) return false;
        vector<long long> nums(v.begin(), v.end());
        for(i=0;i<min(n,k+1);i++){
            auto it=m.upper_bound(nums[i]);
            //cout<<nums[i]<<": "<<((it!=m.end())?it->first:-1)<<" ";
            if(it!=m.end() && abs(it->first-nums[i])<=t) return true;
            else if(it!=m.begin() && m.size()>0){
                it--;
                //cout<<it->first;
                if(abs(it->first-nums[i])<=t) return true;
            }
            //cout<<endl;
            m[nums[i]]++;
        }
        //cout<<"H\n";
        for(;i<n;i++){
            m[nums[i-k-1]]--;
            if(m[nums[i-k-1]]==0) m.erase(nums[i-k-1]);
            auto it=m.upper_bound(nums[i]);
            //cout<<nums[i]<<": "<<((it!=m.end())?it->first:-1)<<" ";
            if(it!=m.end() && abs(it->first-nums[i])<=t) return true;
            else if(it!=m.begin() && m.size()>0){
                it--;
                //cout<<it->first;
                if(abs(it->first-nums[i])<=t) return true;
            }
            //cout<<endl;
            m[nums[i]]++;
        }
        return false;
    }
};