class Solution {
public:
    string makeRange(int start, int end) {
        ostringstream oss;
        if (start != end) {
            oss << start << "->" << end;
        } else {
            oss << start;
        }
        return oss.str();
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int len = nums.size();
        if (len == 0) return result;
        
        // we have two pointer for range-starter and range-ender
        int start=nums[0], end=nums[0];

        for (int i=1; i<len; i++) {
            // if it is continous number, move the end pointer;
            if (nums[i] == end + 1) {
                end = nums[i];
                continue;
            }
            
            //if the number is not continous, push the range into result
            //and reset the start and end pointer
            result.push_back(makeRange(start, end));
            start = end = nums[i];
        
        }
        
        //for the last range
        result.push_back(makeRange(start, end)); 
        
        return result;
    }
};
