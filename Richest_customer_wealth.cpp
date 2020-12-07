class Solution 
{
    
public:
    int maximumWealth(vector<vector<int>>& accounts) 
{
      int maximum = 0;
      int total = 0;
      
      for (auto& itr : accounts) 
      {
        for (auto& itr1 : itr) 
          total += itr1;
        if (total > maximum)  
          maximum = total;
        total = 0;
      }
      
      return maximum;  
    }
};