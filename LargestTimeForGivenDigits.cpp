class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string ans="";
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int k=0;k<4;k++)
                {
                    if(j==i||i==k||j==k)
                        continue;
                    else
                    {
                        string h=to_string(A[i])+to_string(A[j]);
                        string m=to_string(A[k])+to_string(A[6-i-j-k]);
                        string res=h+":"+m;
                        if(h<"24"&&m<"60")
                        ans=max(ans,res);
                    }
                }
            }
        }
        
        return ans;
        
    }
};