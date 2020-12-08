class FrontMiddleBackQueue {
private:
    vector<int> q;
    int sz;
public:
    
    FrontMiddleBackQueue() {
        sz=0;
    }
    
    void pushFront(int val) {
        q.insert(q.begin(), val);
        sz++;
    }
    
    void pushMiddle(int val) {
        int pos=(sz)/2;
        q.insert(q.begin()+pos, val);
        sz++;
    }
    
    void pushBack(int val) {
        q.push_back(val);
        sz++;
    }
    
    int popFront() {
        if(q.size()==0) return -1;
        else{
            int val = q[0];
            q.erase(q.begin());
            sz--;

            return val;
        }
    }
    
    int popMiddle() {
        if(q.size()==0) return -1;
         int pos=(sz-1)/2;
        int val = q[pos];
        q.erase(q.begin()+pos);
        sz--;
        return val;
    }
    
    int popBack() {
        if(q.size()==0) return -1;
        int val = q[sz-1];
        q.pop_back();
        sz--;
        
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */