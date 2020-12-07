class Solution {
public:
    vector<string> ans;
    vector<vector<char>> v={{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    void dfs(string& d, string past, int idx){
        if(idx==d.size()){
            ans.push_back(past);
        }
        else{
            for(auto ch:v[d[idx]-'2']){
                dfs(d, past+ch, idx+1);
            }
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return ans;
        dfs(digits, "", 0);
        return ans;
    }
};