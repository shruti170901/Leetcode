class Solution {
public:
    pair<int,int> di(int dividend,int divisor){
        if(dividend<divisor) return {dividend,0};
        pair<int,int> a= di(dividend>>1,divisor);
        dividend=(dividend & 1) + (a.first<<1) ;
        if(dividend<divisor) return{dividend,a.second<<1};
        return {dividend-divisor,(a.second<<1)+1};
    }
    int divide(int dividend, int divisor) {
        if(divisor==INT_MIN) return dividend==INT_MIN?1:0;
        if(dividend==INT_MIN ) {
            if(divisor==1)return INT_MIN;
            if (divisor==-1) return INT_MAX;
            return (((dividend<0)^(divisor<0))?-1:1)*(di(abs(dividend+abs(divisor)),abs(divisor)).second+1);
        }
        
        return ((((dividend<0)^(divisor<0))?-1:1)*di(abs(dividend),abs(divisor)).second);
    }
};