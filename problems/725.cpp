#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<int> vi;

bool NoDupl(int a, int b)
{
    if (b < 10000 && a < 10000)
        return false;
    bool C[10] = {0};
    int D[2] = {a, b};
    if (b < 10000 || a < 10000)
        C[0] = true;
    for (int i = 0; i < 2; ++i)
    {
        while (D[i])
        {
            if (C[D[i] % 10])
                return false;
            C[D[i] % 10] = true;
            D[i] /= 10;
        }
    }
    return true;
}

int main()
{
    int n, cnt = 0;
    while (cin >> n, n)
    {
        if (0 < cnt++)
            cout << '\n';
        vi Res;
        for (int i = 1000; i * n <= 99999; ++i)
            if (NoDupl(i, i * n))
                Res.push_back(i);
        if (!Res.empty())
            for (int i : Res)
                cout << i * n << " / " << setfill('0') << setw(5) << i << " = " << n << '\n';
        else
            cout << "There are no solutions for " << n << ".\n";
        
    }
    
}
