/*
    There is a special kind of apple tree that grows apples every day for n days. On the ith day, 
    the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] 
    the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.

    You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.

     Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.
     
     Input: apples = [1,2,3,5,2], days = [3,2,1,4,2]
     Output: 7
     
     */

class Solution {
public:
    int eatenApples(vector<int>& A, vector<int>& D) {
        int d=1;
        int ans=0;
        priority_queue<pair<int,int>> q;
        int i=0;
        while(i<A.size()||!q.empty())
        {
            if(i<A.size())
                q.push({-(d+D[i]),A[i]});
            i++;
            while(!q.empty()&&-(q.top().first)<=d)
                q.pop();
            if(q.size())
            {
                auto p=q.top();
                q.pop();
                p.second--;
                ans++;
                if(p.second>0)
                    q.push(p);
            }
            d++;
        }
        return ans;
    }
};
