class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int l=0, r, m=A.size(), n=B.size();
        if(m<=n){
            r=m;
            while(l<=r){
                int i=(l+r)/2, j=(m+n+1)/2;
                j-=i;
                
                if(i>l && A[i-1]>B[j]) r=i-1;
                else if(i<r && B[j-1]>A[i]) l=i+1;
                else{
                    int maxl, minr;
                    if(i==0) maxl=B[j-1];
                    else if(j==0) maxl=A[i-1];
                    else maxl=max(A[i-1], B[j-1]);
                    if((m+n)%2) return maxl;
                    
                    if(i==m) minr=B[j];
                    else if(j==n) minr=A[i];
                    else minr=min(A[i], B[j]);
                    return (maxl+minr)/2.0;
                }
                
            }
            
        }
        else{
            r=n;
            while(l<=r){
                int i=(l+r)/2, j=(m+n+1)/2;
                j-=i;
                if(i>l && B[i-1]>A[j]) r=i-1;
                else if(i<r && A[j-1]>B[i]) l=i+1;
                else{
                    int maxl, minr;
                    if(i==0) maxl=A[j-1];
                    else if(j==0) maxl=B[i-1];
                    else maxl=max(B[i-1], A[j-1]);
                    if((m+n)%2) return maxl;
                    
                    if(i==n) minr=A[j];
                    else if(j==m) minr=B[i];
                    else minr=min(B[i], A[j]);
                    return (maxl+minr)/2.0;
                }     
            }
        }
        return 0;
    }
};