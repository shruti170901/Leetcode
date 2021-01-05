class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int res=t-3000;
        q.push(t);
        while(q.front()<res)
            q.pop();
        return q.size();
    }
};