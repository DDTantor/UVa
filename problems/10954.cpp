#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    while (cin >> n, n)
    {
        priority_queue<ll, vector<ll>, greater<ll> > PQ;
        for (int i = 0; i < n; ++i)
            cin >> k, PQ.push(k);
            
        int total = 0;
        while(PQ.size() > 1)
        {
            ll a1, a2;
            a1 = PQ.top(); PQ.pop();
            a2 = PQ.top(); PQ.pop();
            total += a1 + a2;
            PQ.push(a1 + a2);
        }
        cout << total << '\n';
    }
}
