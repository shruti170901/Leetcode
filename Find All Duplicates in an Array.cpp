// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& A) {
        int i, n=A.size();
        for(i=0;i<n;i++) A[i]--;
        for(i=0;i<n;i++){
            if(A[i]!=i){
                while(A[i]!=i && A[A[i]]!=A[i]) swap(A[i], A[A[i]]);
            }
        }
        for(i=0;i<n;i++) cout<<A[i]<<" "; cout<<endl;
        vector<int> ans;
        for(i=0;i<n;i++) if(A[i]!=i) ans.push_back(A[i]+1);
        return ans;
    }
};