#include <iostream>

using namespace std;

int main()
{
    int s, b, r, l, R[100001], L[100001];
    while (cin >> s >> b, s || b)
    {
        for (int i = 0; i < s + 1; ++i)
            R[i] = i + 1, L[i] = i - 1;
            
        for (int i = 0; i < b; ++i)
        {
            cin >> l >> r;
            if (L[l] < 1)
                cout << "* ";
            else
                cout << L[l] << ' ';
            if (R[r] > s)
                cout << "*\n";
            else
                cout << R[r] << '\n';
            
            L[R[r]] = L[l];
            R[L[l]] = R[r];
        }
        cout << "-\n";
    }
}
