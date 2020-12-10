class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> a;
        int x=arr2.size();
        int y=arr1.size();
        int i,j;
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                if(arr2[i]==arr1[j])
                {
                    a.push_back(arr1[j]);
                    arr1[j]=-1;
                }
                
            }
        }
        sort(arr1.begin(),arr1.end());
        for(i=0;i<y;i++)
        {
                if(arr1[i]>-1)
                    a.push_back(arr1[i]);
        }
     return a;   
    }
};