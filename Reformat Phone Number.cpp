/*
This problem appeared in Weekly contest 220(now over)
You are given a phone number as a string number. number consists of digits, spaces ' ', and/or dashes '-'.

You would like to reformat the phone number in a certain manner. Firstly, remove all spaces and dashes.
Then, group the digits from left to right into blocks of length 3 until there are 4 or fewer digits. The final digits are then grouped as follows:

2 digits: A single block of length 2.
3 digits: A single block of length 3.
4 digits: Two blocks of length 2 each.
The blocks are then joined by dashes. Notice that the reformatting process should never produce any blocks of length 1 and produce at most two blocks of length 2.

Return the phone number after formatting.

Input: number = "1-23-45 6"
Output: "123-456"

*/
class Solution {
public:
    string reformatNumber(string number) {
        string ns="";
        int len=number.length();
        for(int i=0;i<len;i++)
        {
            if(number[i]!='-'&&number[i]!=' ')
                ns+=number[i];
        }
        string nss="";
        int rem=ns.length();
        int i=0;
        while(rem>4)
        {
            int c=0;
            while(c<3)
            {
                nss+=ns[i];
                i++;c++;
                rem--;
            }
            nss+='-';
        }
        if(rem==2)
        {
            int c=0;
            while(c<2)
            {
                nss+=ns[i];
                i++;c++;
                rem--;
            }
        }
        else if(rem==3)
        {
            int c=0;
            while(c<3)
            {
                nss+=ns[i];
                i++;c++;
                rem--;
            }
        }
        else
        {
            int c=0;
            while(c<2)
            {
                nss+=ns[i];
                i++;c++;
                rem--;
            }
            nss+='-';
            c=0;
            while(c<2)
            {
                nss+=ns[i];
                i++;c++;
                rem--;
            }
        }
        return nss;
    }
};
