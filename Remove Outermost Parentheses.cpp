class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int cur_balance = 0, starting_pos = 0;
        for (int cur_pos = 0; cur_pos < S.size(); ++ cur_pos) {
            if (cur_pos != 0 && cur_balance == 0) {
                res += S.substr(starting_pos+1, cur_pos-starting_pos-2);                
                starting_pos = cur_pos;
            } 
            cur_balance = S[cur_pos] == '(' ? cur_balance + 1 : cur_balance - 1;
        }
        return res + S.substr(starting_pos+1, S.size()-starting_pos-2);
    }
};
