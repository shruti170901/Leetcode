class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n=stones.size();
        for(int i = 0; i<n;i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size()>1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int c = max(b,a) - min(a,b);
            if(c)
                pq.push(c);
        }
        int ans = 0;
        if(!pq.empty())
            ans = pq.top();
        return ans;
    }
};