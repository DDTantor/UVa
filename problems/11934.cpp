#include <iostream>

using namespace std;

bool clap(int n)
{
    if (!(n % 7))
        return true;
        
    while (n)
    {
        if (n % 10 == 7)
            return true;
        n /= 10;
    }
    return false;
}

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k, n || m || k)
    {
        int num = 0, p = -1, d = 1;
        while (k)
        {
            num++;
            if (d == m && clap(num))
                k--;
            if (d == 1 || d == n)
                p = -p;
            d += p;
        }
        cout << num << '\n';
    } 
}
