/*
This problem appeared in weekly contest 220(now past)
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array.
That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
*/

class Solution {
public:
    void constructTree(int low,int high,int pos,int *dp,int *segTree)
    {
        if(low==high)
        {
            segTree[pos]=dp[low];
            return;
        }
        int mid=(low+high)/2;
        constructTree(low,mid,(2*pos)+1,dp,segTree);
        constructTree(mid+1,high,(2*pos)+2,dp,segTree);
        segTree[pos]=max(segTree[(2*pos)+1],segTree[(2*pos)+2]);
        return;
    }
    int rangeQueries(int low,int high,int qlow,int qhigh,int *segTree,int pos)
    {
        //no overlap
        if(qhigh<low||qlow>high)
            return INT_MIN;
        //total overlap
        if(qlow<=low&&qhigh>=high)
            return segTree[pos];
        //partial overlap
        int mid=(low+high)/2;
        int left=rangeQueries(low,mid,qlow,qhigh,segTree, (2*pos)+1);
        int right=rangeQueries(mid+1,high,qlow,qhigh,segTree, (2*pos)+2);
        return max(left,right);
    }
    void update(int low,int high,int qlow,int qhigh,int *segTree,int pos,int new_val)
    {
        //no overlap
        if(qhigh<low||qlow>high)
            return;
        //total overlap
        if(qlow<=low&&qhigh>=high)
        {
            segTree[pos]=new_val;
            return;
        }
        //partial overlap
        int mid=(low+high)/2;
        update(low,mid,qlow,qhigh,segTree,(2*pos)+1,new_val);
        update(mid+1,high,qlow,qhigh,segTree,(2*pos)+2,new_val);
        segTree[pos]=max(segTree[(2*pos)+1],segTree[(2*pos)+2]);
        return;
    }
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        int si_segTree=(2*pow(2,ceil(log2(n))))-1;
        int *segTree=(int *)malloc(si_segTree*sizeof(int));
        int *dp=(int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
            dp[i]=INT_MIN;
        dp[n-1]=nums[n-1];
        constructTree(0,n-1,0,dp,segTree);
        for(int i=n-2;i>=0;i--)
        {
            dp[i]=nums[i]+rangeQueries(0,n-1,i+1,min(i+k,n-1),segTree,0);
            update(0,n-1,i,i,segTree,0,dp[i]);
        }           
        int ans=dp[0];
        free(dp);
        free(segTree);
        return ans;
        
    }
};
