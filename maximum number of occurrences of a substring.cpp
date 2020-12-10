//https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/submissions/

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
     
        int start=0,r=0;
        unordered_map<int,int> count;           	
        unordered_map<string,int> occur;        
        
        for(int i=0;i<s.length();i++)			
        {
            count[s[i]]++;						
            if(i-start+1>minSize)                 
            {
                if(--count[s[start]]==0)		
                    count.erase(s[start]);
                start++;
            }
            if(i-start+1==minSize&&count.size()<=maxLetters)    
            {
                r=max(r,++occur[s.substr(start,i-start+1)]);
        
            }
        
        }
        return r;
        
        
        
        
        
    }
};