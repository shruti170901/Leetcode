class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1, countA = 0, countB = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0 && (S[i] == '#' || countA > 0)) S[i--] == '#' ? ++countA : --countA;
            while(j >= 0 && (T[j] == '#' || countB > 0)) T[j--] == '#' ? ++countB : --countB;
            if(i < 0 || j < 0) return i == j;
            if(S[i--] != T[j--]) return false;
        }
        return i == j;
    }
};
