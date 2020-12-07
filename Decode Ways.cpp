class Solution {
public:
    int numDecodings(string s) {
        
        if ((s.empty())||(s[0]=='0'))
        {
            return 0;
            
        }
        
        int a=1;
        int b=1;
        for (int i=1; i<s.size();i++){
            int c=0;
            if ((s[i]=='0')){
                int d = (s[i-1]-'0');
                if( (d<3)&&(d>0) ){c=b;}
            }
            if (s[i]!='0'){
                if (s[i-1]=='0'){c = a;}
                else{
                    int e = (s[i-1]-'0')*10+(s[i]-'0');
                    if (e<=26) {c = a+b;}
                    else{c =a;}
                }
            }
            b=a;
            a=c;   
        }
        return a;    
    }
};