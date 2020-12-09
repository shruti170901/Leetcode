// https://leetcode.com/problems/unique-morse-code-words/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& w) {
        string arr[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        int i, j, n=w.size(), ans;
        for(i=0;i<n;i++){
            string temp="";
            for(j=0;j<w[i].size();j++){
                temp+=arr[w[i][j]-'a'];
            }
            s.insert(temp);
        }
        ans=s.size();
        return ans;
    }
};