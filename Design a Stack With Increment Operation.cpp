// https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
public:
    int size;
    vector<int> v;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(v.size()+1<=size) v.push_back(x);
    }
    
    int pop() {
        int p=-1;
        if(v.size()>0){
            p=*v.rbegin();
            v.pop_back();
        }
        return p;
    }
    int min(int a, int b){
        if(a<b) return a;
        return b;
    }
    void increment(int k, int val) {
        for(int i=0;i<min(k, v.size());i++) v[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */