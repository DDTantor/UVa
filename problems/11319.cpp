#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint> 

using namespace std;

typedef unsigned long long ll;
typedef vector<double> vd;
typedef vector<vd> vvd;

vd GaussianElimination(int N, vvd& A)
{
    double t;
    vd X(N);
    for (int j = 0; j < N - 1; ++j)
    {
        int l = j;
        for (int i = j + 1; i < N; ++i)
            if (fabs(A[i][j]) > fabs(A[l][j]))
                l = i;

        for (int k = j; k <= N; ++k)
            t = A[j][k], A[j][k] = A[l][k], A[l][k] = t;

        for (int i = j + 1; i < N; ++i)
            for (int k = N; k>= j; --k)
                A[i][k] -= A[j][k] * A[i][j] / A[j][j];
    }

    for (int j = N - 1; j >= 0; --j)
    {
        t = 0;
        for (int k = j + 1; k < N; ++k)
            t += A[j][k] * X[k];

        X[j] = (A[j][N] - t) / A[j][j];
    }

    return X;
}

ll eval(ll x, vector<ll> A)
{
    ll res = A[A.size() - 1];
    for (int i = A.size() - 2; i >= 0; --i)
        res = res * x + A[i];
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    ll a, t;
    cin >> t;
    while (t--)
    {
        vvd A(7, vd(8, 1.0));
        for (int i = 0; i < 7; ++i)
            cin >> A[i][7];

        for (int i = 0; i < 7; ++i)
        {
            for (int j = 1; j < 7; ++j)
                A[i][j] = (i + 1) * A[i][j - 1];
        }
        
        vd X = GaussianElimination(7, A);
        vector<ll> Y(7);
        for (int i = 0; i < 7; ++i)
            Y[i] = ll(X[i]);
        
        bool good = true;
        for (ll i = 8; i <= 1500; ++i)
        {
            cin >> a;
            good &= (a == eval(i, Y));
        }

        for (int i : Y)
            good &= (i >= 0 && i < 1001);
        
        if (good)
        {
            for (int i = 0; i < Y.size(); ++i)
            {
                if (i) cout << ' ';
                cout << Y[i];
            }
        }
        else
            cout << "This is a smart sequence!";

        cout << '\n';
    }
}
