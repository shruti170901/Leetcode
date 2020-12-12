class Solution {
public:
    int fib(int N) {
        int i,res,k1=0,k2=1;
        res=0;
        if(N==0)
            return 0;
        else if(N==1)
            return 1;
        else
        {
            for(i=2;i<=N;i++)
            {
                 res=k1+k2;   
                 k1=k2;
                 k2=res;
            }
          return res;     
        }
    }
};