class Solution {
public:
    bool valid(vector<int> &weights,int D,int mid){
        int counts=1,sum=0;
        for(auto x:weights){
            sum+=x;
            if(sum>mid){
                counts++;
                sum=x;
                if(counts>D){
                    return false;
                }
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int total_weights=0,max_weight=INT_MIN;
        for(auto x:weights){
            total_weights+=x;
            max_weight=max(max_weight,x);
        }
        if(D==1){
            return total_weights;
        }
        int start=max_weight,end=total_weights;
        while(start<=end){
            int mid= start+(end-start)/2;
            if(valid(weights,D,mid)){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
            
    }
};
