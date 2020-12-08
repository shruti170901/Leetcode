class Solution {
public:
    string longestPalindrome(string s) 
    
    {
     int maxlength=0,length=0,length1=0,length2=0;
     int i,r=0,l=0;
               
        for(i=0;i<s.length();i++)
        {   
            length1=palindrome_detector(s,i,i);
            length2=palindrome_detector(s,i,i+1);
            length=max(length1,length2);
            if(length > maxlength)
            {
                maxlength=length;
                l=i-(length-1)/2;
                r=i+(length/2);    
            }
            
        }
        return s.substr(l,maxlength);
    }


    int palindrome_detector(string s,int l,int r)
    {
        while(l>=0 && r<s.length() && s[l]==s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }


};