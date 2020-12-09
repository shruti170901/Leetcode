class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int cnt=0;
        int i=0,m=a.size();
        while(i<m){
            if (a[i] == 0 && (i == 0 || a[i - 1] == 0) && (i == m-1 || a[i + 1] == 0)) {
                a[i] = 1;
                cnt++;
            }
            i++;
        }
        return(n<=cnt);
    }
};
