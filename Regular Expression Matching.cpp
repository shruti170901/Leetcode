class Solution {
public:
    int min(int x, int y){
        if(x<y) return x;
        return y;
    }
    bool isMatch(string s, string p) {
        //string temp=".*";
        //cout<<temp.substr(2).size()<<endl;
        int i, j, n=s.size(), m=p.size();
        //cout<<s<<" "<<p<<endl;
        if(m==0) return n==0;
        bool first=(n>0 && (s[0]==p[0] || p[0]=='.'));
        //cout<<first<<endl;
        if(m>=2 && p[1]=='*'){
            return (isMatch(s, p.substr(2)) || (first && isMatch(s.substr(min(s.size(),1)), p)));
        }
        else{
            return first && isMatch(s.substr(1), p.substr(1));
        }
    }
};