//Given a word, you need to judge whether the usage of capitals in it is right or not.
// We define the usage of capitals in a word to be right when one of the following cases holds:
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.

// Example problem
// Input: "USA"
// Output: True

//  C++ Program

class Solution {
public:
    bool detectCapitalUse(string word) {
        int c=0;
        for(int i=0;i<word.length();i++)
        {
        if(isupper(word[i]))
            c++;
        }
            if(c==word.length() or c==0 or (isupper(word[0]) and c==1))
                return true;
            else
                return false;

    }
};
