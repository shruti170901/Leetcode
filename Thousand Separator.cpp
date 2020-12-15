class Solution {
public:
    string thousandSeparator(int n) {
        if (n==0) return "0";
        int cnt=0;
        string result;
        while( n > 0 ){
            int m = n % 10;
            result.insert(result.begin(),   ('0' + m) );
            cnt++;
            n /= 10;
            if (cnt % 3 == 0 && n > 0) {
                result = '.' + result;
            }

        }
        return result;
    }
};
