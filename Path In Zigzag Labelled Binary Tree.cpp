// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int n=0, i, temp;
        temp=label;
        while(temp){
            temp/=2;
            n++;
        }
        temp=1<<(n-1);
        if(n%2==0) label=(1<<n)-1-(label-temp);
        while(label>0){
            ans.push_back(label);
            label/=2;
        }
        reverse(ans.begin(), ans.end());
        for(i=1;i<ans.size();i+=2){
            temp=ans[i]; n=0;
            while(temp){
                n++;
                temp/=2;
            }
            ans[i]=(1<<n)-1-(ans[i]-(1<<(n-1)));
        }
        return ans;
    }
};