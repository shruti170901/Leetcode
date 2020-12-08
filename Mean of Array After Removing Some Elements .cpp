class Solution {
public:
    double trimMean(vector<int>& arr) {
        if(arr.size()==0) return 0;
        sort(arr.begin(), arr.end());
        int l=arr.size();
        int st = (l*5)/100;
        double fsum=0, lsum=0;
        for(int i=0; i<st; i++){
            fsum+=arr[i];
            lsum+=arr[l-i-1];
        }
        double tsum=accumulate(arr.begin(), arr.end(), 0);
        double ans=(tsum-fsum-lsum)/(l-2*(st));
        return ans;
    }
};