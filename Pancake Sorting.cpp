// https://leetcode.com/problems/pancake-sorting/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        int i, j, n=A.size();
        if(n<=1) return ans;
        for(i=n;i>0;i--){
            for(j=0;j<n;j++){
                if(A[j]==i) break;
            }
            if(j!=i-1){
                ans.push_back(j+1);
                ans.push_back(i);
                int k=0;
                while(k<j){
                    swap(A[k], A[j]);
                    k++; j--;
                }
                k=0;
                j=i-1;
                while(k<j){
                    swap(A[k], A[j]);
                    k++; j--;
                }
            }
        }
        //for(int it:A) cout<<it<<" ";
        return ans;
    }
};