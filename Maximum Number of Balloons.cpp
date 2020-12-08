class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> m{{'b',0},{'a',0},{'l',0},{'o',0},{'n',0}};
        
        for(char c : text){
            if(m.find(c) != m.end())
                m[c]++;
        }
        
        m['l']/=2; m['o']/=2;

        int min = INT_MAX;
        
        for(auto it = m.begin();it!=m.end();it++){
            if(it->second<=min)
                min = it->second;
        }
        return min;
    }
};