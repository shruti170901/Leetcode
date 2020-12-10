class Solution {
public:
    int check(vector<int> &v,int l,int r,int sa,int sb,int f) {
        if(l==r) {
            if(f==1) sa += v[l];
            else sb += v[l];
            
            if(sa>=sb) return 1;
            else return 2;
        }
        if(f==1) {
            int t1 = check(v,l+1,r,sa+v[l],sb,2);
            int t2 = check(v,l,r-1,sa+v[r],sb,2);
            
            if(t1==1 || t2==1) return 1;
            else return 2;
        }
        else {
            int t1 = check(v,l+1,r,sa,sb+v[l],1);
            int t2 = check(v,l,r-1,sa,sb+v[r],1);
            
            if(t1==2 || t2==2) return 2;
            else return 1;
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()==0)  return true;
        int f = check(nums,0,nums.size()-1,0,0,1);
        
        if(f==1) return true;
        else return false;
    }
};