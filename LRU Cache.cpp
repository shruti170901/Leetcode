// https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    unordered_map<int, int> time, m;
    set<pair<int, int>> s;
    int cap, t;
    LRUCache(int capacity) {
        time.clear(); m.clear(); s.clear(); cap=capacity; t=0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        int ti=time[key];
        s.erase({ti, key});
        s.insert({t, key});
        time[key]=t;
        t++;
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key]=value;
            s.erase({time[key], key});
            time[key]=t;
            s.insert({t, key});
            t++;
            return;
        }
        if(m.size()<cap){
            s.insert({t, key});
            time[key]=t;
            m[key]=value;
            t++;
            return;
        }
        pair<int, int> p=*s.begin();
        s.erase(s.begin());
        time.erase(p.second);
        m.erase(p.second);
        s.insert({t, key});
        time[key]=t;
        m[key]=value;
        t++;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */