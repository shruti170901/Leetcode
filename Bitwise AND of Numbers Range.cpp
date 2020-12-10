class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        if(m==0)return 0;
        if(m==n)return m;
        int ans=0;
        int a,b;
        while(m && n)
        {
            a=floor(log2(m)); 
            b=floor(log2(n));
            int x=(int)pow(2,a);
            if(a==b && x<m  && x<n)
            {
                ans+=x;
                m-=x;
                n-=x;
                
            }
            else{
                break;
            }
        }
       
        
        return a==b?ans+(int)pow(2,a):ans+0;
    }
};