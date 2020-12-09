// https://leetcode.com/problems/self-dividing-numbers/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int temp, flag;
        vector<int> ans;
        for(int i=left;i<=right; i++){
            temp=i;
            flag=1;
            while(temp){
                if(temp%10==0 || i%(temp%10)!=0){
                    flag=0;
                    break;
                }
                temp/=10;
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};