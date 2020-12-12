class Solution {
public:
    int thirdMax(vector<int>& nums) {
       vector<int> a(4, 0);
        vector<bool> b(4, false);

        for (auto x : nums) {
            if (b[1] && x == a[1]) continue;
            if (b[2] && x == a[2]) continue;
            if (b[3] && x == a[3]) continue;
            
            b[0] = true;
            a[0] = x; 
            
            for(int i = 1; i < 4; ++i) {
                if (b[i] && a[i] > x) break;
                swap(a[i], a[i-1]);
                swap(b[i], b[i-1]);
            }
        }
    
        if(b[1])
            return a[1];
        else
            return a.back();
        
    }
};
