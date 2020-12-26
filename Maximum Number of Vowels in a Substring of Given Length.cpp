class Solution
{
public:
    // return true if character is vowel
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxVowels(string s, int k)
    {

        // right pointer
        int right = 0;

        // left pointer
        int left = 0;

        // current vowel count
        int vcount = 0;

        // max vowel count
        int max_vcount = 0;

        int n = s.length();

        // Slide right till k and count vowel
        for (right = 0; right < k; right++)
            if (isVowel(s[right]))
                vcount++;

        // update max vowel count
        max_vcount = max(max_vcount, vcount);

        // Slide right and left till string ends and count vowel in k length substring
        while (right < n)
        {
            // count vowel including right
            if (isVowel(s[right]))
                vcount++;

            // count vowel excluding left
            if (isVowel(s[left]))
                vcount--;

            // increase right and left for next Slide
            left++;
            right++;

            // update max vowel count
            max_vcount = max(max_vcount, vcount);
        }

        return max_vcount;
    }
};