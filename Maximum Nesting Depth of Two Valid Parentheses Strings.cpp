// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int i, n=seq.size(), o=0, c=0;
        for(i=0;i<n;i++){
            if(seq[i]=='('){
                ans.push_back(o);
                o^=1;
            }
            else{
                ans.push_back(c);
                c^=1;
            }
        }
        return ans;
    }
};