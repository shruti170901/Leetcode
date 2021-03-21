// C++ implementation to toggle bits in
// the given range
#include <bits/stdc++.h>
using namespace std;

// function to toggle bits in the given range
unsigned int toggleBitsFromLToR(unsigned int n,
                                unsigned int l, unsigned int r)
{
    // calculating a number 'num' having 'r'
    // number of bits and bits in the range l
    // to r are the only set bits
    int num = ((1 << r) - 1) ^ ((1 << (l - 1)) - 1);

    // toggle bits in the range l to r in 'n'
    // and return the number
//Besides this, we can calculate num as: num=(1<<r)-l .
    return (n ^ num);
}

// Driver program to test above
int main()
{
    unsigned int n = 50;
    unsigned int l = 2, r = 5;
    cout << toggleBitsFromLToR(n, l, r);
    return 0;
}
