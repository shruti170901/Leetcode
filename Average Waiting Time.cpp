/* Appeared in Biweekly contest 42(now past)
  There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:

arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
timei is the time needed to prepare the order of the ith customer.
When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order.
The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.

Return the average waiting time of all customers. Solutions within 10^-5 from the actual answer are considered accepted.
Input: customers = [[1,2],[2,5],[4,3]]
Output: 5.00000
*/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        int time=0;
        for(auto it=customers.begin();it!=customers.end();it++)
        {
            if(time==0)
            {
                ans+=(*it)[1];
                time=(*it)[0]+(*it)[1];
            }
            else
            {
                ans+=(*it)[1];
                if(time>(*it)[0])
                {
                    ans+=(time-(*it)[0]);
                    time+=(*it)[1];
                }
                else
                {
                    time=(*it)[0]+(*it)[1];
                }
            }
        }
        return ans/customers.size();
    }
};
