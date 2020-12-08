// https://leetcode.com/problems/design-hashset/

class MyHashSet {
public:
    /** Initialize your data structure here. */
    bitset<10000001> b;
    MyHashSet() {
        
    }
    
    void add(int key) {
        b[key]=1;
    }
    
    void remove(int key) {
        b[key]=0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return b[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */