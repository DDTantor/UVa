#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
    int n;
    while (cin >> n, n)
    {
        vi best;
        int a;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            if (a) best.push_back(a);
        }

        if (!best.size())
            cout << "0";
        else
        {
            cout << best[0];
            for (int i = 1; i < best.size(); ++i)
                cout << ' ' << best[i];
        }
        
        cout << '\n';
    }
}
