class Solution {
public:
    string nPermute(string str, long int n) { 
        long int i = 1; 
        do { 
            if (i == n) 
                break; 
            i++; 
        } while (next_permutation(str.begin(), str.end())); 
        return str; 
    } 
    
    string getPermutation(int n, int k) {
        string str;
        for(int i=1;i<=n;i++) str+=to_string(i);
        return nPermute(str,k);
    }
};
