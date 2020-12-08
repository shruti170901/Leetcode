class Solution {

public:
    void wiggleSort01(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) { return x > y; });
        int half = (nums.size() / 2);
        
        for (int i=0; i<half; i++) {
            int v = nums[half+i];
            nums.erase(nums.begin() + half + i );
            nums.insert(nums.begin() + (2*i), v);
        }
        cout << endl;
    }

    
    void wiggleSort02(vector<int>& nums) {
        int n = nums.size();
        
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]
    
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
    void wiggleSort(vector<int>& nums) {
        return wiggleSort02(nums); //~140ms
        return wiggleSort01(nums); //~230ms
    }
};
