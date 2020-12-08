class Solution {
public:
    int minOperations(vector<string>& logs) {
        int x=0;
        for(auto c: logs){
            if(c=="../") x=max(0, x-1);
            else if(c=="./") continue;
            else x++;
        }
        
        return x;
    }
};