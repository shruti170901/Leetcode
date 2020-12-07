// https://leetcode.com/problems/restore-ip-addresses/

class Solution {
public:
    bool isValid(string s){
        if(s.size()==0) return false;
        int temp=stoi(s);
        if(s.size()==1 && temp>=0 && temp<=9) return true;
        if(s.size()==2 && temp>=10 && temp<=99) return true;
        if(s.size()==3 && temp>=100 && temp<=255) return true;
        return false;
    }
    vector<string> restoreIpAddresses(string s) {
        int i, j, k, l, n=s.size();
        vector<string> ans;
        string temp="", s1, s2, s3, s4;
        if(n<4 || n>12) return ans;
        for(i=1;i<=3 && i-1+3<s.size();i++){
            s1=s.substr(0, i);
            if(isValid(s1)){
                for(j=1;j<=3 && i+j-1+2<s.size();j++){
                    s2=s.substr(i, j);
                    if(isValid(s2)){
                        for(k=1;k<=3 && i+j+k-1+1<s.size();k++){
                            s3=s.substr(i+j, k);
                            if(isValid(s3)){
                                s4=s.substr(i+j+k);
                                if(isValid(s4)){
                                    ans.push_back(s1+'.'+s2+'.'+s3+'.'+s4);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};