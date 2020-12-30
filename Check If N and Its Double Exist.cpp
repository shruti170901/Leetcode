#Check If N and Its Double Exist
/*Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(arr[i]==2*arr[j] || arr[j]==2*arr[i])
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};