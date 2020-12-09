// https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int l=0, u=0;
        for(char x:word){
            if(x<='Z') u++;
            else l++;
        }
        if(u==0 || l==0) return true;
        if(u==1 && word[0]<='Z') return true;
        return false;
    }
};