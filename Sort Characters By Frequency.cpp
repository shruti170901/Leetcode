class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> c;
        for(auto x:s){
            c[x]++;
        }
        sort(s.begin(),s.end(),[&](char a,char b){
            return c[a]>c[b]||(c[a]==c[b]&&a<b);
        });
        return s;
    }
};
