/* Appeared in Biweekly Contest 42(now past)
   You are given a binary string binary consisting of only 0's or 1's. You can apply each of the following operations any number of times:

    Operation 1: If the number contains the substring "00", you can replace it with "10".
      For example, "00010" -> "10010"
    Operation 2: If the number contains the substring "10", you can replace it with "01".
      For example, "00010" -> "00001"
  Return the maximum binary string you can obtain after any number of operations. 
  Binary string x is greater than binary string y if x's decimal representation is greater than y's decimal representation.
  
  Input: binary = "000110"
  Output: "111011"
  */

class Solution {
public:
    string maximumBinaryString(string binary) {
        int len=binary.length();
        int str=0,end=len-1;
        string ns="",last="";
        while(str<len&&binary[str]=='1')
        {
            ns+='1';
            str++;
        }
        while(end>=0&&binary[end]=='1')
        {
            last+='1';
            end--;
        }
        if(str>=end)
            return binary;
        int kc=0;
        while(str<=end)
        {
            int next=str+1;
            while(next<=end&&binary[next]=='1')
            {
                kc++;
                next++;
            }
            if(next>end)
                break;
            ns+='1';
            str=next;
        }
        ns+='0';
        while(kc--)
            ns+='1';
        ns+=last;
        return ns;
    }
};
