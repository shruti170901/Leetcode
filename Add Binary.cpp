class Solution 
{
public:
  string addBinary(string a, string b) 
  {
    int la = a.size();
    int lb = b.size();
    
    string diffZeros;
    for(int i = 0; i < abs(la-lb); ++i)
      diffZeros += "0";
    
    if(la < lb)
    {
      a = diffZeros + a;  
      la = lb;
    }
    else if(lb < la)
    {
      b = diffZeros + b;
      lb = la;
    }
    
    string ans;
    int carry = 0;
    for(int i = la-1; i >= 0; --i)
    {
      int sum = (a[i] - '0') + (b[i] - '0') + carry;
      carry = sum / 2;
      
      ans = (sum % 2 == 0) ? "0" + ans : "1" + ans; 
    }
    
    if(carry > 0)
      ans = "1" + ans;
    
    return ans;
  }
};
