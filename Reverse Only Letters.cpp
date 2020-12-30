// Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place,
// and all letters reverse their positions.

// Example Input
// Input: "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"

// C++ Program
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n=S.length();
        int i,j;
        i=0;j=n-1;
        while(i<j)
        {
            if(isalpha(S[i]) && isalpha(S[j]))
            {
                swap(S[i],S[j]);
                i++;
                j--;
            }
            else if(!isalpha(S[i]))
                i++;
            else if(!isalpha(S[j]))
                j--;
        }
        return S;

    }
};
