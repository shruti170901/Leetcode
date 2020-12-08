class Solution {
public:
    int romanToInt(string s) {
        int num=0, n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='M') num+=1000;
            else if(s[i]=='D') num+=500;
            else if(s[i]=='C'){
                if(i<n-1 && s[i+1]=='M') i++, num+=900;
                else if(i<n-1 && s[i+1]=='D') i++, num+=400;
                else num+=100;
            }
            else if(s[i]=='L') num+=50;
            else if(s[i]=='X'){
                if(i<n-1 && s[i+1]=='C') i++, num+=90;
                else if(i<n-1 && s[i+1]=='L') i++, num+=40;
                else num+=10;
            }
            else if(s[i]=='V') num+=5;
            else{
                if(i<n-1 && s[i+1]=='X') i++, num+=9;
                else if(i<n-1 && s[i+1]=='V') i++, num+=4;
                else num+=1;
            }
        }
        return num;
    }
};