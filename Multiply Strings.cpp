class Solution {
public:
    string multiply(string num1, string num2)
    {
        int n1=num1.size(),n2=num2.size(),carry,mx=-1;
        vector <string> s(n2);
        string zero="";

        for(int i=n2-1;i>=0;i--)
        {
            carry=0;
            s[i]=zero;
            for(int j=n1-1;j>=0;j--)
            {
                int x=(num1[j]-'0')*(num2[i]-'0');
                x+=carry;
                carry=x/10;
                s[i]=(char(x%10+'0'))+s[i];
            }
            if(carry!=0)
            {
                s[i]=to_string(carry)+s[i];
            }

            mx=max(mx,(int)s[i].size());
            zero+='0';
        }

        for(int i=n2-1;i>=0;i--)
        {
            s[i]=string(mx-(int)s[i].size(),'$')+s[i];
        }

        carry=0;
        string ans="";

        for(int i=mx-1;i>=0;i--)
        {
            int x=0;
            for(int j=n2-1;j>=0;j--)
            {
                if(s[j][i]!='$')x+=s[j][i]-'0';
            }
            x+=carry;
            carry=x/10;
            ans=(char)(x%10+'0')+ans;
        }

        if(carry!=0)
        {
            ans=to_string(carry)+ans;
        }

        //delete leading zeroes (if any)
        int z=0;

        for(int i=0;i<(int)ans.size()-1;i++)
        {
            if(ans[i]!='0')break;
            z++;
        }

        return ans.substr(z,(int)ans.size()-z);
    }
};