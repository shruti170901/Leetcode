class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int sum=0, carry=0;
        for(int i=A.size()-1; i>=0; i--){
            sum = A[i] + K%10+carry;
            K/=10;
            res.push_back(sum%10);
            carry=sum/10;
        }
        
        while(K){
            sum = K%10+carry;
            K/=10;
            res.push_back(sum%10);
            carry=sum/10;
        }
        if(carry)res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};