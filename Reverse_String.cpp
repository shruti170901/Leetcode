#Reverse String
/*Write a function that reverses a string. The input string is given as an array of characters char[].*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i;
        char temp;
        for(i=0;i<n/2;i++)
        {
            temp=s[n-i-1];
            s[n-i-1]=s[i];
            s[i]=temp;
        }
        
    }
};