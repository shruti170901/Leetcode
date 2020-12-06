class TopVotedCandidate {
public:
    vector<int> leading;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        unordered_map<int,int> M;
        int maxi=0,current_max=persons[0];
        for(int i:persons){
            M[i]++;
            maxi = max(M[i],maxi);
            
            //Update current max
            if(M[i]==maxi){
                current_max = i;
            }
            
            if(M[i]>=M[current_max]){
                leading.push_back(i);
            }
            else{
                leading.push_back(current_max);
            }
        }
    }
    
    int q(int t) {
        auto it = upper_bound(times.begin(),times.end(),t);
        it--;
        int index = it - times.begin();
        return leading[index];
    }
};