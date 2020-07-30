class Solution {
public:
    int rangeSum(vector<int>& arr, int n, int left, int right) {
        int i, j; 
        vector<int> cArray(n + 1,0); 
        for (i = 0; i < n; i++) 
            cArray[i + 1] = cArray[i] + arr[i]; 
        vector<long long int> subArrSum; 
        for (i = 1; i <= n; i++) 
            for (j = i; j <= n; j++) 
                subArrSum.push_back(cArray[j] - cArray[i - 1]); 
        sort(subArrSum.begin(), subArrSum.end());   
        int totalSum = 0;
        for (i = left-1; i < right; i++) 
            totalSum += subArrSum[i]; 
        return totalSum; 
    }
};
