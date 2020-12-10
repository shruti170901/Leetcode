class Solution {
public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int counter = 0, i, j, k;
    int arr_length = arr.size();
    for (i=0;i<arr_length;++i) 
    {
      for (j=i+1;j<arr_length; ++j)
      {
        if (abs(arr[i] - arr[j]) > a) 
        {
          continue;
        }
        for (k=j+1;k<arr_length;++k) 
        {
          if ((abs(arr[i]-arr[k])<=c) && (abs(arr[j] - arr[k]) <= b)) 
          {
            counter++;
          }
        }
      }
    }
    return counter;
  }
};