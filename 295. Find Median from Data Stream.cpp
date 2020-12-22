class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_h;
    priority_queue<int, vector<int>, greater<int>> min_h;
    MedianFinder() {
        // MedianFinder *obj = new MedianFinder();
    }
    
    void addNum(int num) {
        max_h.push(num);
        min_h.push(max_h.top());
        max_h.pop();
        if(min_h.size()>max_h.size()){
            max_h.push(min_h.top());
            min_h.pop();
        }
    }
    
    double findMedian() {
        if(max_h.size()==min_h.size()){
            return (max_h.top()+min_h.top())*0.5;
        }
        else{
            return max_h.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
