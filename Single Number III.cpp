class Solution {
   public:
   vector <int> singleNumber(vector<int>& nums) {
      int xor_result = 0, n=nums.size(),pos = 0,num1 = 0;
      for (int i=0;i < n; i++) 
         xor_result = xor_result ^ nums[i];
      while ((xor_result & (1 << pos)) == 0) 
         pos++;
      for (int i=0;i < n; i++) 
         if ((nums[i] & (1 << pos)) != 0) 
            num1 = num1 ^ nums[i];
      int num2 = xor_result ^ num1;
      return {num1, num2};
   }
};
