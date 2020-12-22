// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution {
public:
   double average(vector<int>& salary) {
        double sum = 0;
        int min=1e6,max=-1e6;
        if(salary[0]>salary[1]){
            max = salary[0];
            min = salary[1];
        }
        else{
            max = salary[1];
            min = salary[0];
        }
        for(int i=2; i<salary.size(); i++){
           if(salary[i]>max){
               sum += max;
               max = salary[i];
            }
            else if(salary[i]<min){
                sum+= min;
                min = salary[i];
            }
            else sum+=salary[i];
        }
        return sum/(salary.size()-2);
    }
};
