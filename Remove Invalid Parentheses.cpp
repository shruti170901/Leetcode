class Solution {
public:
    bool isBracket(char ch){
        return (ch=='(' || ch==')');
    }
    
    bool isValid(string str){
        int count = 0;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]=='(')
                count++;
            else if(str[i]==')')
                count--;
            
            if(count<0)
                return false;
        }
        return (count==0);
    }
    
    vector<string> removeInvalidParentheses(string str) {
        vector<string> res;
        if(str.size()==0)
        {
            res.push_back("");
            return res;
        }
        queue<string> q;
        set<string> visited;
        bool level = false;
        
        q.push(str);
        visited.insert(str);
        string temp;
        
        while(!q.empty())
        {
            str = q.front();
            q.pop();
            if(isValid(str))            
            {
                res.push_back(str);
                level = true;
                visited.insert(str);
            }
            if(level)           //The minimum edits are controlled by this
                continue;
            for(int i=0; i<str.length(); i++)
            {
                if(!isBracket(str[i]))
                    continue;
                temp = str.substr(0,i) + str.substr(i+1);
                if(visited.find(temp)==visited.end())
                {
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }
        return res;
    }
};