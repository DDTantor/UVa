#include <iostream>
#include <bitset>

using namespace std;

bool IsBad(int n)
{   
    bitset<9> b;
    while (n)
    {
        int d = n % 10;
        if (b[d])
            return true;
        b[d] = 1;
        n /= 10;
    }
    return false;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int sum = m - n + 1;
        for (int i = n; i <= m; ++i)
            if (IsBad(i))
                sum--;
        cout << sum << endl;
    }
}
