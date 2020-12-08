class Solution {
public:
    int maxSubSum(vector<int>&a){
        int sumSF=0, res=0, mini=a[0];
        for(int i=0; i<a.size(); i++){
            mini=min(mini, a[i]);
            sumSF = max(0, sumSF+a[i]);
            res = max(res, sumSF);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size();
        if(n==0) return 0;
        int maxi=A[0];
        for(int i=0; i<n; i++) maxi=max(maxi, A[i]);
        if(maxi<=0) return maxi;
        int val1 = maxSubSum(A);
        int totalSum=0;
        for(int i=0; i<n; i++){
            totalSum += A[i];
            A[i]=-1*A[i];
        }
        
        int val2 = totalSum + maxSubSum(A);
        return max(val1, val2);
    }
};