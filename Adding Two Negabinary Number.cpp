//please refer to this chart for better understanding
/*
Sum     Bit	Carry Output Comment
−2	010	0	1	  01	−2 occurs only during subtraction.
−1	011	1	1	  01
0	000	0	0	  00
1	001	1	0	  00
2	110	0	−1	  11
3	111	1	−1	  11	3 occurs only during addition.*/
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int carry = 0;
        vector<int> res;
        int p1 = (int)arr1.size() -  1, p2 = (int)arr2.size() -  1;
        while( p1 >=0 || p2 >=0 || carry!= 0) {
           if(p1 >= 0) carry += arr1[p1--];
           if(p2 >= 0) carry += arr2[p2--];
           res.push_back(abs(carry) & 1);
           carry = carry > 1 ? -1 : carry < 0 ? 1 : 0;
        }

        while(res.size() > 1 &&res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
