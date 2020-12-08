class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int min_i = INT_MAX, flag_min = 0; 
        
        while(s<=e) {
            
            int mid = (s+e)/2;
            if(nums[mid] == target){
                if(mid == min_i) break;
                min_i = min(min_i, mid);
                e = mid-1;
                flag_min = 1;
            }
            else if(nums[mid]>=target)
                e = mid-1;
            else
                s = mid+1;
            
        }
        s = 0;
        e = nums.size()-1;
        int max_i = INT_MIN, flag_max = 0; 
        
        while(s<=e) {
            
            int mid = (s+e)/2;
            if(nums[mid] == target){
                if(mid == max_i) break;
                max_i = max(max_i, mid);
                s = mid+1;
                flag_max = 1;
            }
            else if(nums[mid]>=target)
                e = mid-1;
            else
                s = mid+1;
            
        }
        
        vector<int> vec;
        
        if(flag_min){
            vec.push_back(min_i);
            vec.push_back(max_i);
        }
        else {
            vec.push_back(-1);
            vec.push_back(-1);
            
        };
        return vec;
        
    }
};
