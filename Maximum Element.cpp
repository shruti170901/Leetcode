PROBLEM_DESCRIPTION:-

/*You have an empty sequence, and you will be given  queries. Each query is one of these three types:

1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the maximum element in the stack.
*/

SOLUTION:-

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main() 
{
    stack<int> s;    
    int n,j,k;
    cin >> n;
    while(n--)
    {
        cin >> j;
        if(j == 1)
        {
            cin >> k;
            s.push(max(k, s.size()>0?s.top():k));
        }
        else if(j == 2)
            s.pop();
        else if(j == 3)
            cout << s.top() << '\n';
    }
    return 0;
}
