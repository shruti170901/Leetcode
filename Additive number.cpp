// PROBLEM LINK: https://leetcode.com/problems/additive-number/submissions/



class Solution {
public:
    bool isAdditiveNumber(string num) {
        
        if (num.size() < 3) {
            return false;
        }
        std::string_view str(num);
		
        for (int i = 0; i < num.size() - 2; ++i) {
            for (int j = i+1; j < num.size() - 1; ++j) {
                if (j > i+1 && num[i+1] == '0') break;
                if (isAdditiveSuffix(str.substr(0, i+1), str.substr(i+1, j - i), str.substr(j+1))) return true;
            }
        }
        return false;
    }
    
    bool isAdditiveSuffix(string_view first, string_view second, string_view suffix) {
        std::string sum_string;
        longSumm(first, second, sum_string);
        if (suffix.substr(0, sum_string.size()) == sum_string) {
            if (suffix.size() == sum_string.size()) return true;
            return isAdditiveSuffix(second, sum_string, suffix.substr(sum_string.size()));
        }
        return false;
    }
    
    void longSumm(string_view first, string_view second, std::string& out) {
        if (second.size() > first.size()) {
            swap(second, first);
        }        
        out = std::string{first};

        char c = 0;
        for (int i = out.size()-1, j = second.size()-1; i >= 0; --i, --j) {
            char d = 0;
            if (j >= 0) {
                d += (second[j] - '0');
            }
            d += (out[i] - '0') + c;
            
            out[i] = '0' + (d % 10);
            if (d > 9) {
                c = 1;
            } else {
                c = 0;
            }
        }
        if (c > 0) {
            out.insert(out.begin(), '0' + c);
        }
        
    }
};