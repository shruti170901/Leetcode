class Solution {
public:
    int numTeams(vector<int>& rating) {
        int i,ctr = 0;
        for(i=0;i<rating.size();i++){
            for(int j=i;j<rating.size();j++){
                if(rating[j]>rating[i]){
                   for(int k = j; k<rating.size();k++){
                      if(rating[k]>rating[j]){
                         ++ctr;
                    }
                }

                }
            }
        }
        for(i=0;i<rating.size();i++){
            for(int j=i;j<rating.size();j++){
                if(rating[j]<rating[i]){
                for(int k = j; k<rating.size();k++){
                    if(rating[k]<rating[j]){
                         ++ctr;
                    }
                }

                }
            }
        }
        return ctr;
    }
};
