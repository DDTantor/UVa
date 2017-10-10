#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll t, n, best, bestid;
vector<ll> lis, P, A;

void Print(int id)
{
    if (id == -1)
        return;

    Print(P[id]);
    cout << A[id] << '\n';
}

int main()
{
    cin >> t;
    cin.ignore();
    while (t--)
    {
        A.clear();
        while (cin.ignore(), cin.peek() != '\n' && !cin.eof())
            cin >> n, A.push_back(n);

        n = A.size();
        P.assign(n, -1);
        lis.assign(n, 1);
        lis[0] = best = 1;
        bestid = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
                if (A[j] < A[i] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1, P[i] = j; 
                    
            if (lis[i] > best)
                best = lis[i], bestid = i;
        }
        
        cout << "Max hits: " << best << '\n';
        Print(bestid);
        if (t)
            cout << '\n';
    }
}
