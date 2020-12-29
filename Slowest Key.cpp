class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int y=releaseTimes.size();
        int x=0, i, a;
        releaseTimes.insert(releaseTimes.begin(), 0);
        char c=0;
        for(i=1;i<=y;i++) 
        {
            a = releaseTimes[i] - releaseTimes[i-1];  
            if(a>x) 
            {
                x=a;
                c=keysPressed[i-1];  
            } 
            else if((a==x)&&(keysPressed[i-1]>c))
            {
                c=keysPressed[i-1];
            }
        }
        return c;
    }   
};