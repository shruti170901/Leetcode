// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int row) {
        vector<int> a{1}, b{1,1};
        if(row==0) return a;
        if(row==1) return b;
        int i=1;
        while(i<row){
            a.clear();
            a.push_back(1);
            for(int j=0;j<b.size()-1;j++){
                a.push_back(b[j]+b[j+1]);
            }
            a.push_back(1);
            b=a;
            i++;
        }
        return a;
    }
};