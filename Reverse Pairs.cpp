class Solution {
public:
    int ans;
    int arr[50005];           // Auxiliary array to store number during merging
    void msort(vector<int>& nums, int st, int ed){
        if (ed-st<2) return;
        int mid=st+(ed-st)/2;
        msort(nums, st, mid);
        msort(nums, mid, ed);
        
        int i=st, j=mid, k=0;
        int a=st, b=mid;
        
        // two pointer to count "Important pairs"
        while (a<mid && b<ed){      
            if (nums[a]>2ll*nums[b]){
                ans+=(mid-a);
                b++;
            }
            else{
                a++;
            }
        }
        
        // normal merge of two sorted arrays
        while (i<mid && j<ed){       
            if (nums[i]<nums[j]){
                arr[k++]=nums[i++];
            }
            else{
                arr[k++]=nums[j++];
            }
        }
        while (i<mid){
            arr[k++]=nums[i++];
        }
        k--;
        while(k>-1){
            nums[st+k]=arr[k];
            k--;
        }
        return ;
    }
    
    
    int reversePairs(vector<int>& nums) {
        ans=0;
        msort(nums, 0, nums.size());
        return ans;
    }
};