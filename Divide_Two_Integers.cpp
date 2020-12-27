// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long x=abs(dividend), y=abs(divisor);
        long long cnt=0, temp=0, temc=0;
        while(x-y>=0){
            temp=y; temc=1;
            while(x-temp>=0){
                temp*=2;
                temc*=2;
            }
            temp/=2; temc/=2;
            x-=temp;
            cnt+=temc;
        }
        if(dividend<0) cnt*=-1;
        if(divisor<0) cnt*=-1;
        if(cnt<INT_MAX) return cnt;
        return INT_MAX;
    }
};