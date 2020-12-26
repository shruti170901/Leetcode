class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int prev = INT_MIN;
        
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            while (!s.empty() && s.top() < *it) {
                if (prev > s.top())
                    return true;
                prev = s.top();
                s.pop();
            }
            
            s.push(*it);
        }
        
        return !s.empty() && prev > s.top();
    }
};