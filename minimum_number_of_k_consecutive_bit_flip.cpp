//Link to the problem: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/submissions/



class Solution {
 public:
  int minKBitFlips(vector<int>& A, int K) 
  {
    int final_answer = 0;
    int flipped_time = 0;

    for (int i = 0; i < A.size(); ++i) 
    {
      if (i >= K && A[i - K] == 2)
        --flipped_time;
      if (flipped_time % 2 == A[i]) 
      {
        if (i + K > A.size())
        {return -1;}
        ++final_answer;
        ++flipped_time;
        A[i] = 2;
      }
    }

    return final_answer;
  }
};