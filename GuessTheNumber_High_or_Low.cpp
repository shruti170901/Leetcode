/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=1,high=n,mid;
        while(low<=high)
        {
            mid=low-(low-high)/2;
           
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==1)
                low=mid+1;
            else
                high=mid-1;
            
        }
        return -1;
    }
};