class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
        int i,j;
        int x=words.size();
        for(i=0;i<x;i++)
        {
            int flag=0;
            for(j=0;j<words[i].size();j++)
            {
                int k;
                for(k=0;k<allowed.size();k++)
                    if(allowed[k]==words[i][j])
                        flag++;
                
            }
            if(flag==words[i].size())
                count++;
        }
        return count;
    }
};