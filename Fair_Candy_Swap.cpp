class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> res(2);
        unordered_set<int> s;
        int sum1= 0, sum2 =0;
        for(int i = 0; i < A.size(); i++){
            sum1 += A[i];
        }
        for(int i = 0; i < B.size(); i++){
            sum2 += B[i];
            s.insert(B[i]);
        }
   
        int diff = (sum1 - sum2)/2;
        for(int i = 0; i < A.size(); i++){
            if(s.count(A[i] - diff)){
                res[0] = A[i];
                res[1] = A[i] - diff;
                break;
            }
        }        
        return res;     
    }  
};

