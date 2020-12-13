class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int length = arr.size();
        int i, j=length+count(arr.begin(), arr.end(), 0);
        for(int i = length - 1; i >= 0; i --){
            if(--j<length)
                arr[j] = arr[i];
            if((!arr[i]) && (--j<length))
                arr[j] = 0;
        }
    }
};