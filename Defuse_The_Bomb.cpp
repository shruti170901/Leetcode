#include <iostream>
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(k==0)
            {
                v.push_back(0);
            }
            int sum=0;
            if(k>0)
            {   
                 int q=i+1;
            for(int j=1;j<=abs(k);j++)
            {
               
                if(q==n)
                {
                    q=0;
                }
                sum+=code[q];
                q++;
            }
            v.push_back(sum);
            }
             if(k<0)
            {      
                  int q=i-1;
            for(int j=1;j<=abs(k);j++)
            {
               
                if(q==-1)
                {
                    q=n-1;
                }
                sum+=code[q];
                q--;
            }
            v.push_back(sum);
            }
        }
        return v;
    }
};
