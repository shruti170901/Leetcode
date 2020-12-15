class Solution {
public:
    string decodeString(string s)
    {
        int i=0;
        // stack<char> w;
        while(i<s.size())
        {
            
            if(s[i]==']')
            {
                // dbg(i);
                string w="";
                int k=0,posl=-1,posr=i+1;
                int len1=0,len2=0;
                bool ok =false;
                string ks="";

                for(int j=i-1;j>=0;j--)
                {
                    if(s[j]>='0' && s[j]<='9')
                    {
                        ks+=s[j];
                        continue;
                    }
                    if(ok)
                    {
                        posl=j;
                        break;
                    }
                    if(s[j]=='[')
                    {
                        ok=true;
                        continue;
                    }
                    w+=s[j];
                    len1++;
                }
                reverse(ks.begin(),ks.end());
                k=stoi(ks);
                len2=(int)ks.size();
                i+=-len1-len2-2+k*len1;
                // dbg(k);
                reverse(w.begin(),w.end());
                string z="";
                while(k--)
                {
                    z+=w;
                }
                
                s=s.substr(0,posl+1)+z+s.substr(posr,s.size()-posr);
                
            }
            else
            {
                i++;
            }
        }
        
        return s;
    }
};