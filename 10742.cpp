#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi primes;
void Sieve(int max)
{
    vi sieve;
    for (int i = 1; i < max + 1; ++i)
        sieve.push_back(i);
    sieve[0] = 0;
    for (int i = 2; i <= max + 1; ++i)
    {
        if (sieve[i - 1] != 0)
        {
            primes.push_back(sieve[i - 1]);
            for (int j = 2 * sieve[i - 1]; j < max + 1; j += sieve[i - 1])
                sieve[j - 1] = 0;
        }
    }
}

int main()
{
    Sieve(10000000);
    int n, c = 1;
    while (cin >> n, n)
    {
        cout << "Case " << c++ << ": ";
        int cnt = 0;
        for (int i = 0; primes[i] < n; ++i)
        {
            auto it = lower_bound(primes.begin(), primes.end(), n - primes[i]);
            while (it - primes.begin() > i)
            {
                int s = it - primes.begin();
                it--;
                if (primes[s] + primes[i] > n)
                        continue;
                cnt += s - i;
                break;
            }
        }
        cout << cnt << '\n';
    }
}
