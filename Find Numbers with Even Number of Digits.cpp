class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        int no_of_digits, x, flag=0;
        for(int i=0;i<nums.size();i++)
        {  
            no_of_digits = 0;
            x = nums[i];
            while(x)
            {
                x = x / 10;  
                no_of_digits++; 
            }
            if(no_of_digits % 2 == 0)
            {  
                flag++;
            }
        }
        return flag; 
    }
};