/* Appeared in Weekly Contest 221(now past)
  You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

  Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

  Return true if a and b are alike. Otherwise, return false.
  
  Input: s = "book"
  Output: true
  
  */
class Solution {
public:
    bool halvesAreAlike(string s) {
        int len=s.length();
        int hlen=len/2;
        int c_a=0,c_b=0;
        int i=0,j=hlen;
        while(j<len&&i<hlen)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
                c_a++;
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U')
                c_b++;
            i++;
            j++;
        }
        if(c_a==c_b)
            return true;
        return false;
    }
};
