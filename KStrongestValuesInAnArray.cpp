class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int m = arr[(n-1)/2];
        vector<int> front;vector<int> back;vector<int> ans;
        for(int i=0;i<(n-1)/2;i++)front.push_back(arr[i]);
        for(int i=(n-1);i>(n-1)/2;i--)back.push_back(arr[i]);
        int fs=front.size(),bs=back.size();
        int j=0,pk=0,a,b;
        int dj=0,pj=0;
        if(k==n){ans.push_back(m);k--;}
        for(int i=0;i<k;i++){
            dj=0;pj=0;
            if(j>bs-1)a=m;
            else {a=back[j++];dj=1;}
            if(pk>fs-1)b=m;
            else {b=front[pk++];pj=1;}
            if(a-m>=m-b){
                ans.push_back(a);
                if(pj==1)pk--;
            }
            else {
                ans.push_back(b);
                if(dj==1)j--;
            }
        }
        return ans;
    }
};
