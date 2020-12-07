// https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        string temp="";
        for(int i=1;i<=n;i++){
            temp="";
            if(i%3 && i%5) temp=to_string(i);
            if(i%3==0) temp+="Fizz";
            if(i%5==0) temp+="Buzz";
            ans.push_back(temp);
        }
        return ans;
    }
};