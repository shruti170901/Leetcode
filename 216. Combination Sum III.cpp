class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void solve(int &k,int &n,int i){
        if(k==0&&n==0){
            ans.push_back(temp);
            return;
        }
        for(int l=i;l<=min(9,n);l++){
            temp.push_back(l);
            k--;
            n-=l;
            solve(k,n,l+1);
            k++;
            n+=l;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        solve(k,n,1);
        return ans;
    }
};
