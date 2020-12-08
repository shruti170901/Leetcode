// https://leetcode.com/problems/word-ladder-ii/

class Solution {
private:
    unordered_set<string> wordList;
    vector<vector<string>> ans;
    unordered_set<string> visited;
            
    int level = 1;
    int minLevel = INT_MAX;
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,vector<string> &words ) {

        //Putting all words in a set
        for(auto word: words)
            wordList.insert(word);
        //wordList.insert(endWord); Cant insert endWord now
            
        //Queue of Paths
        queue<vector<string>> q;
        q.push({beginWord});
        

        while (!q.empty()) 
        {
            vector<string> path = q.front(); q.pop();
            
            if (path.size() > level)
            {
                //reach a new level
                for (string w : visited) 
                    wordList.erase(w);
                
                //visited.clear();
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }
            
            
            string lastWord = path.back();
            
            addNeighboursToQ(lastWord,path,q,endWord);
        }
        
        return ans;
    }
    
    void addNeighboursToQ(string curr,vector<string> path,queue<vector<string>> &q,const string &endWord)
    {
            for(int i=0;i<curr.size();i++) 
            {
                char originalChar = curr[i];

                for(int j=0;j<26;j++)
                {
                    curr[i] = j + 'a';
                    
                    if(wordList.find(curr)!=wordList.end())
                    {
                        //cout<<curr<<"   added"<<endl;
                        vector<string> newpath = path;
                        newpath.push_back(curr);
                        
                        visited.insert(curr);
                        
                        
                        if (curr == endWord) {
                            minLevel = level;
                            ans.push_back(newpath);
                        }
                        else
                            q.push(newpath);
                        
                    }
                }
                
                curr[i] = originalChar;
            }//i
    }
};