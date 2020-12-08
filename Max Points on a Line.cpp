// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int i, j, k, x, y, mx=0, sz, len=0, n=p.size();
        if(n<=2) return n;
        map<pair<int, int>, int> m;
        for(i=0;i<n;i++){
            int same=0; len=0;
            m.clear();
            for(j=i+1;j<n;j++){
                x=p[j][0]-p[i][0]; y=p[j][1]-p[i][1];
                if(x==0 && y==0) same++;
                else if(x==0){
                    m[{0, 1}]++;
                    len=max(len, m[{0,1}]);
                }
                else if(y==0){
                    m[{1,0}]++;
                    len=max(len, m[{1,0}]);
                }
                else{
                    if(x<0 && y<0){
                        x*=-1; y*=-1;
                    }
                    else if(x>0 && y<0){
                        x*=-1; y*=-1;
                    }
                    int temp=__gcd(abs(x),abs(y));
                    x/=temp;
                    y/=temp;
                    m[{x,y}]++;
                    len=max(len, m[{x,y}]);
                }
            }
            //cout<<len<<" "<<same<<endl;
            mx=max(mx, len+same+1);
        }
        return mx;
    }
};