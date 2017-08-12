#include <iostream>
#include <cstring>

using namespace std;

int cs = 0, n, nums[16];

bool isprime(int a)
{
    for (int i = 2; i * i <= a; ++i)
        if (!(a % i))
            return false;

    return true;
}

bool isgood(int a, int c, int k)
{
    for (int i = 0; i < c; ++i)
        if (nums[i] == k)
            return false;
    
    return isprime(a);
}

void backtrack(int c)
{
    if (c == n && isprime(nums[0] + nums[c - 1]))
    {
        for (int i = 0; i < n; ++i)
        {
            if (i)
                cout << ' ';
            cout << nums[i];
        }
        cout << '\n';
    }
    else if (c < n)
        for (int i = 2; i <= n; ++i)
            if (isgood(nums[c - 1] + i, c, i))
                nums[c] = i, backtrack(c + 1);
}

int main()
{
    while (cin >> n)
    {
        if (cs)
            cout << '\n';
        cout << "Case " << ++cs << ":\n";
        memset(nums, 0, sizeof(nums));
        nums[0] = 1;
        backtrack(1);
    }
}
