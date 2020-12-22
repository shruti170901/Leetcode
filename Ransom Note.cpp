class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count1(26), count2(26);
        int i;
        bool ans = true;
        for(i=0;i<ransomNote.length();i++)
            count1[ransomNote[i]-'a']++;   
        for(i=0;i<magazine.length();i++)
            count2[magazine[i]-'a']++;
        for(i=0;i<26;i++)
            if(count1[i]>count2[i])
                ans=false;
        return ans;
    }
};
