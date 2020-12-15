class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int i=0,j=0;
        int idx = 0;  
        int n = chars.size();
        while(i<n){
            while(j<n && chars[i]==chars[j])
                j++;
            int num=j-i;
            string c = to_string(num);
            
            chars[idx] =chars[i];
            idx++;
            
            if(num>1){
                for(int x=0;x<c.size();x++){
                    chars[idx] = c[x];
                    idx++;
                }      
            }
            
            i=j;
         }
        return idx;
    }
};
