// https://leetcode.com/problems/distribute-candies-to-people/

class Solution {
public:
    long long sum(unsigned long long n){
        return ((long long)n*(n+1))/2;
    }
    vector<int> distributeCandies(int candies, int num) {
        long long i, j, l=0, r=1000000, m, temp;
        while(l<r){
            m=l+(r-l)/2+1;
            temp=(m+1)*num;
            if(sum(temp)<=candies) l=m;
            else r=m-1;
        }
        cout<<l<<endl;
        vector<int> ans(num);
        if(candies<sum(num)){
            for(i=0;i<num;i++){
                ans[i]=min((long long)candies, i+1);
                candies-=ans[i];
            }
        }
        else{
            candies-=sum((l+1)*num);
            cout<<candies<<endl;
            for(i=0;i<num;i++){
                ans[i]=sum(l)*num+(l+1)*(i+1);
                cout<<ans[i]<<" ";
                if(candies>0){
                    ans[i]+=min((long long)candies, (l+1)*num+i+1);
                    candies-=min((long long)candies, (l+1)*num+i+1);
                }
            }
        }
        return ans;
    }
};