class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector <string> ans;
        for(int i=0;i<words.size();i++)
        {
            int count1=0,count2=0,count3=0;
            for(int j=0;j<words[i].length();j++)
            {
            if(tolower(words[i][j])=='q'||tolower(words[i][j])=='w'||tolower(words[i][j])=='e'||tolower(words[i][j])=='r'||tolower(words[i][j])=='t'||tolower(words[i][j])=='y'||tolower(words[i][j])=='u'||tolower(words[i][j])=='i'||tolower(words[i][j])=='o'||tolower(words[i][j])=='p')
                count1++;
                else if(tolower(words[i][j])=='a'||tolower(words[i][j])=='s'||tolower(words[i][j])=='d'||tolower(words[i][j])=='f'||tolower(words[i][j])=='g'||tolower(words[i][j])=='h'||tolower(words[i][j])=='j'||tolower(words[i][j])=='k'||tolower(words[i][j])=='l')
                count2++;
                else 
                    count3++;
            }
            if(words[i].length()==count1||words[i].length()==count2||words[i].length()==count3)
            { ans.push_back(words[i]);  }
             
            
        }
        return ans;
        
    }
};