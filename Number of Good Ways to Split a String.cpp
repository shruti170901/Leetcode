class Solution {
public:
    int numSplits(string s) {
        return (waysToSplit(s));
    }
private:



int waysToSplit(string s) 
{ 
    int n = s.length(); 
    int answer = 0; 
    vector<int> prefix(n,0); 
    vector<int> suffix(n,0);
  
    int seen[26] = { 0 }; 
  
    for (int i = 0; i < n; i++) { 
  
        int prev = (i - 1 >= 0 ?  
              prefix[i - 1] : 0); 
        if (seen[s[i] - 'a'] == 0) { 
            prefix[i] += (prev + 1); 
        } 
        else
            prefix[i] = prev; 
        seen[s[i] - 'a'] = 1; 
    } 
    memset(seen, 0, sizeof(seen)); 
    suffix[n - 1] = 0; 
    for (int i = n - 1; i >= 1; i--) { 
        int prev = suffix[i]; 
        if (seen[s[i] - 'a'] == 0) { 
            suffix[i - 1] += (prev + 1); 
        } 
        else
            suffix[i - 1] = prev; 
        seen[s[i] - 'a'] = 1; 
    }  
    for (int i = 0; i < n; i++) { 
        if (prefix[i] == suffix[i]) 
            answer++; 
    } 
    return answer; 
} 
};
