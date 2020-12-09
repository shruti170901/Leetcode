class Solution {
public:
    int numRescueBoats(vector<int>& ppl, int limit) {
        sort(ppl.begin(), ppl.end());
        int beg=0, end=ppl.size()-1;
        int c=0;
        
        while(beg<=end){
            if(beg!=end && ppl[beg]+ppl[end] <= limit){
                c++;
                beg++;
                end--;
            }else{
                c++;
                end--;
            }
        }
        
        return c;
    }
};