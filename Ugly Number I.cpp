class Solution {
public:
    //greeting algorithm
    bool isUgly(int num) {
        if ( num == 0 ) return false;
        if ( num == 1 ) return true;
        //becasue the 2,3,5 are prime numbers, so, we just simply remove each factors 
        //by keeping dividing them one by one 
        while ( num % 2 == 0 ) num /= 2;
        while ( num % 3 == 0 ) num /= 3;
        while ( num % 5 == 0 ) num /= 5;
        
        return num == 1;
    }
};
