// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string hay, string nee) {
        if(nee=="") return 0;
        int i, n=hay.size(), len=nee.size();
        string comp="";
        i=0;
        while(i<n && comp.size()<len){
            comp+=hay[i++];
        }
        if(i==n) return comp==nee?(i-len):-1;
        while(i<n){
            if(comp==nee) return i-len;
            comp.erase(comp.begin());
            comp+=hay[i++];
        }
        return comp==nee?(i-len):-1;
    }
};