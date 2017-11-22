#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

const ll maxn = 1000000;
ll IsPrime[maxn];
ll IsCirc[maxn];

void sieve()
{
    IsPrime[0] = IsPrime[1] = 1;
    for (ll i = 2; i < maxn; ++i)
        if (!IsPrime[i])
            for (ll j = i * i; j < maxn; j += i)
                IsPrime[j] = 1;
}

void rotate(string& n)
{
    if (n.size() == 1)
        return;

    string a = string(1, n.back());
    n.pop_back();
    n = a + n;
    
}

void iscirc()
{
    for (int i = 0; i < maxn; ++i)
    {
        int flag = 1;
        string tmp = to_string(i);
        do
        {
            flag &= !IsPrime[stoi(tmp)];
            rotate(tmp);
        } while(tmp != to_string(i));

        IsCirc[i] = flag;
    }
    
    for (int i = 1; i < maxn; ++i)
        IsCirc[i] += IsCirc[i - 1]; 
}

int main()
{
    sieve();
    iscirc();
    int a, b;
    while (cin >> a >> b)
    {
        int res = IsCirc[b] - IsCirc[a - 1];
        if (!res)
            cout << "No Circular Primes.\n";
        else if (res == 1)
            cout << "1 Circular Prime.\n";
        else
            cout << res << " Circular Primes.\n";
    }
}
