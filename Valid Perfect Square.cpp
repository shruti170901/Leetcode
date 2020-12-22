class Solution {
public:
    bool isPerfectSquare1(int num) {
        int left = 0, right = num;
        
        while (left <= right) {
            //cout << left << "," << right << endl;
            int mid = left + (right - left)/2;
            int n = mid * mid;
            if ( n == num) return true;
            if ( n < num ) left = mid + 1;
            else right = mid - 1;
        }
        
        return false; 
        
    }
    
    // the stupid way is best & fast.
    bool isPerfectSquare2(int num) {
        for (int i=1; i <= num/i ; i++ ) {
            if ( i*i == num) return true;
        }
        
        return false;
    }
    
    
    bool isPerfectSquare(int num) {
        return isPerfectSquare2(num);
        return isPerfectSquare1(num);
    }
    
};
