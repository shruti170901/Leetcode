class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start=0,end=arr.size()-k-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid+k]-x<x-arr[mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        // if(end==-1){
        //     return vector<int>(arr.begin(),arr.begin()+k);
        // }
        // if((arr[start]-x)>(x-arr[end])){
        //     return vector<int>(arr.begin()+end,arr.begin()+end+k);
        // }
        return vector<int>(arr.begin()+start,arr.begin()+start+k);
    }
};
