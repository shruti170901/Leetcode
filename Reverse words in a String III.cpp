class Solution {
public:
    string reverseWords(string s) {
        int i;
        int k=0;
        for(i=0;i<s.size();i++)
        {
            if(isspace(s[i]))
            {
                reverse(s.begin()+k,s.begin()+i);
                if(k==0)
                    s.insert(i," ");
                k=i;


            }
        }
        reverse(s.begin()+k,s.end());
        if(isspace(s[s.size()-1]))
            s.erase(s.size()-1);
        
     return s;   
    }
};