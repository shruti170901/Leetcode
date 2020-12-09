// https://leetcode.com/problems/valid-number/

class Solution {
public:
    bool isNumber(string s) {
        bool fe=false, fs=false, fd=false, fnum=false, fnume=false;
        int i, n=s.size();
        i=0;
        while(i<n && s[i]==' ') i++;
        if(i==n) return false;
        if(s[i]=='+' || s[i]=='-'){fs=true; i++;}
        else if(s[i]>='0' && s[i]<='9'){fnum=true;i++;}
        else if(s[i]=='.'){fd=true; i++;}
        else return false;
        
        while(i<n){
            if(s[i]==' ') break;
            else if(s[i]>='0' && s[i]<='9' && !fe) fnum=true;
            else if(s[i]>='0' && s[i]<='9' && fe) fnume=true;
            else if(s[i]=='e' && !fe && fnum){
                fe=true;
                if(i<n && (s[i+1]=='+' || s[i+1]=='-')) i++;
            }
            else if(s[i]=='.' && !fd && !fe) fd=true;
            else return false;
            i++;
        }
        while(i<n){
            if(s[i]!=' ') return false;
            i++;
        }
        if(fnum){
            if(fe) return fnume;
            return true;
        }
        else return false;
    }
};