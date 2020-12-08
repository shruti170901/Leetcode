class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        int c=2;
        int sum=0;
        for(int i=2; i<A.size(); i++){
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                c++;
            }else{
                if(c>2){
                    sum += (c-1)*(c-2)/2;
                    c=2;
                }
            }
        }
        if(c>2){
            sum += (c-1)*(c-2)/2;
        }
    
        return sum;
    }
};