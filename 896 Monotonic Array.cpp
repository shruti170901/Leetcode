class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increase = true;
    bool decrease =true;
    for(int i=0;i<A.size()-1;i++)
    {
        if(A[i+1]>A[i])
            decrease = false;
        if(A[i+1]<A[i])
            increase = false;
    
    }
    if(increase==false && decrease ==false)
        return false;
    else
        return true;
        
    }
};