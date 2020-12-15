#include<bits/stdc++.h>
#include<cctype>
#define ll      long long
#define lli     long long int
#define ull     unsigned long long
#define fi      first
#define se      second
#define pb      push_back
#define mp      make_pair
#define all(x)      x.begin(),x.end()
#define mem(x,n)    memset(x,n,sizeof(x))     
#define REP(i,n)    for(ll i=0;i<n;i++)
#define REP1(i,a,b)    for(ll i=a;i<=b;++i)
#define DEP(i,n)      for(ll i=n;i>0;--i)
#define DEP1(i,a,b)     for(ll i=b;i>=a;--i)
#define yes     printf("YES\n")
#define no      printf("NO\n")
#define endl    "\n"
#define mod     1000000007
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0,t;
        for(auto& a: left) {
            t=a;
            ans=max(ans,t);
        }for(auto& a: right) {
            ans= max(ans,n-a);
        }return ans;
    }
};
