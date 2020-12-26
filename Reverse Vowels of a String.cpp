class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (isVowel(s[i]) == true && isVowel(s[j]) == true)
                swap(s[i++], s[j--]);
            if (isVowel(s[i]) == false)
                i++;
            if (isVowel(s[j]) == false)
                j--;
        }
        return s;
    }
    bool isVowel(char s)
    {
        s = tolower(s);
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
            return true;
        return false;
    }
};