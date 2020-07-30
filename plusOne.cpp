class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += c;
            c = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if (c > 0) digits.insert(digits.begin(), c);
        return digits;
    }
};
