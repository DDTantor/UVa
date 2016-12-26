#include <iostream>

using namespace std;

int p, q;

void BinSearch(int mL, int nL, int mR, int nR, int a, int b)
{
    if (a == p && b == q)
    {   
        cout << '\n';
        return;
    }
    cout << ((a * q < b * p)? 'R' : 'L');
    if (a * q < b * p)
        BinSearch(a, b, mR, nR, a + mR, b + nR);
    else
        BinSearch(mL, nL, a, b, a + mL, b + nL);
}

int main()
{
    while (cin >> p >> q, p != 1 || q != 1)
        BinSearch(0, 1, 1, 0, 1, 1);
    
}
