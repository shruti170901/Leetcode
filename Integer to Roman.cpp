class Solution {
public:
    void fill(string &ans, int& num, int base, char low, char high, char higher){
        if(num>=9*base){
            num-=9*base;
            ans+=low;
            ans+=higher;
        }
        else if(num>=5*base){
            ans+=high;
            num-=5*base;
            while(num>=base){
                ans+=low;
                num-=base;
            }
        }
        else if(num>=4*base){
            ans+=low;
            ans+=high;
            num-=4*base;
        }
        else{
            while(num>=base){
                ans+=low;
                num-=base;
            }
        }
    }
    string intToRoman(int num) {
        string ans="";
        while(num>=1000){
            ans+='M';
            num-=1000;
        }
        fill(ans, num, 100, 'C', 'D', 'M');
        fill(ans, num, 10, 'X', 'L', 'C');
        fill(ans, num, 1, 'I', 'V', 'X');
        return ans;
    }
};