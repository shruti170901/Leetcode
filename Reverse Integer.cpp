class Solution {
public:
    int atoi(string s){
        int num=0;
        for(int i=0;i<s.size();i++){
            num=num*10-'0'+s[i];
        }
        return num;
    }
    int reverse(int x) {
        long long lim=INT_MIN, num=x;
        string s="", t=to_string(abs(num)), s1=to_string(INT_MAX), s2=to_string(abs(lim));
        cout<<s1<<endl<<s2<<endl;
        for(int i=t.size()-1;i>=0;i--) s+=t[i];
        if(x>0){
            if(s.size()<s1.size()) return atoi(s);
            else if(s<=s1) return atoi(s);
            else return 0;
        }
        else if(x<0){
            if(s.size()<s2.size()) return -1*atoi(s);
            else if(s<=s1) return -1*atoi(s);
            else return 0;
        }
        return 0;
    }
};