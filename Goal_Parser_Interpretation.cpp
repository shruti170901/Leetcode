class Solution {
public:
    string interpret(string command) {
        int i,x;
        x=command.size();
        string output;
        for(i=0;i<x;)
        {
            if(command[i]=='G')
            {
                output.append("G");
                i++;
            }
            else if(command[i]=='('&&command[i+1]==')')
            {
                output.append("o");
                i+=2;
            }
            else 
            {
                output.append("al");
                i+=4;
            }
        }
        return output;
    }
};