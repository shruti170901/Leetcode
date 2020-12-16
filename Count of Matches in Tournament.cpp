class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        int team = n;
        while(team!=1){
        	matches += team/2;
        	team = (team+1)/2;
        }
        return matches;
    }
};