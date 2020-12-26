class Solution 
{
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
    {
        int flag=0, i=0;
        if(timeSeries.size()==0)
        {
            return 0;
        }
        else{
        for(i=0;i<(timeSeries.size()-1);i++)
        {
            flag = flag + min(duration,timeSeries[i+1]-timeSeries[i]); 
        }
        flag = flag + duration;
        return flag;
        }
    }
};