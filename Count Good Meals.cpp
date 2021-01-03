/*

A good meal is a meal that contains exactly two different food items with a sum of deliciousness equal to a power of two.

You can pick any two different foods to make a good meal.

Given an array of integers deliciousness where deliciousness[i] is the deliciousness of the ith item of food,
return the number of different good meals you can make from this list modulo 10^9 + 7.

Note that items with different indices are considered different even if they have the same deliciousness value.

Input: deliciousness = [1,3,5,7,9]
Output: 4

Input: deliciousness = [1,1,1,3,3,3,7]
Output: 15

*/

#define N 1048576
#define M 1000000007
typedef long long int lli;
class Solution {
public:
    int countPairs(vector<int>& nums) {
        lli *arr=(lli *)calloc((N+1),sizeof(lli));
        for(auto it=nums.begin();it!=nums.end();it++)
            arr[*it]++;                                
        lli pairs=0;
        for(int i=0;i<=N;i++)
        {
            if(arr[i]>0)
            {
                for(int j=0;j<=21;j++)               
                {
                    lli val=pow(2,j);
                    lli temp=val-i;                     
                    if(temp<i||temp>N||arr[temp]==0)    
                        continue;
                    if(temp==i)
                    {
                        if(arr[i]>1)                    
                        {
                        lli temp_ans=0;
                        lli val=arr[i]-1;
                        while(val>0)
                        {
                            temp_ans=((temp_ans%M)+(val%M))%M;
                            val--;
                        }
                        pairs=((pairs%M)+(temp_ans%M))%M;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        lli temp_ans=((arr[i]%M)*(arr[temp]%M))%M;
                        pairs=((pairs%M)+(temp_ans%M))%M;
                    }
                }
            }
        }
        free(arr);
        return pairs;
    }
};
