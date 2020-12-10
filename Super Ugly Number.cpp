//Super Ugly Number
#define ll long long int
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        ll top, i = 0;
        vector<int> arr(n, -1);
        priority_queue<ll, vector<ll>, greater<ll>> pq = {};
        pq.push(1);
        while (!pq.empty() && arr[n - 1] == -1)
        {
            top = pq.top();
            arr[i++] = top;
            pq.pop();
            for (auto elt : primes)
                pq.push(top * elt);
            while (!pq.empty() && top == pq.top())
                pq.pop();
        }
        return arr[n - 1];
    }
};
