class Solution {
public:
    int clumsy(int N) 
    {
     int i,res=N;
     if(N==1)
         res=1;
     if(N==2)
         res=2;  
     if(N==3)
         res=6; 
     if(N==4)
         res=7;
     else if(N>4)
     {
      res=N*(N-1)/(N-2);
       while(1)
       {
           res+=(N-3);
           N-=4;
           if(N==N%4)  
           {
               if(N==1)
                  --res;
               else if(N==2)
                   res-=2;
               else if(N==3)
                   res-=6;
               break;
           }
           res-=N*(N-1)/(N-2);
       }
     }
     return res;
    }
};
