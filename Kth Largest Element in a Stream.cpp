class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int l;
    KthLargest(int k, vector<int>& nums) {
        l = k;
        for(int i = 0; i<nums.size(); i++)
        {
            if(pq.size()<k)
                pq.push(nums[i]);
            else{
                int a = pq.top();
                pq.pop();
                pq.push(max(a,nums[i]));
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<l)
        {
            pq.push(val);
            return pq.top();
        }
        int a = pq.top();
        pq.pop();
        pq.push(max(a,val));
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
