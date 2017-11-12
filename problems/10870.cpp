#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

struct Matrix
{
    vvi A;
    int dim;
    Matrix() {}
    Matrix(int n) : dim(n) { A.assign(n, vi(n));}
    vi &operator [](int n){ return A[n];}
};

ll m;

Matrix operator *(Matrix A, Matrix B)
{
    int n = A.dim;
    Matrix C(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % m) % m;
       
    return C;
}

Matrix operator ^(Matrix A, int k)
{
    int n = A.dim;
    
    Matrix R(n);
    for (int i = 0; i < n; ++i)
        R[i][i] = 1;

    while (k > 0)
    {
        if (k % 2)
            R = R * A;

        A = A * A;
        k /= 2;
    }

    return R;
}

int main()
{
    ll d, n;
    while (cin >> d >> n >> m, d || n || m)
    {
        Matrix F(d);
        vi D(d);
        for (int i = 0; i < d; ++i)
            cin >> F[i][0];
        
        for (int i = 0; i < d; ++i)
        {
            cin >> D[i];
            if (i > 0)
                F[i - 1][i] = 1;
        }
        
        F = F ^ (n - 1);
        ll res = 0;
        for (int i = 0; i < d; ++i)
            res = (res + (F[i][d - 1] * D[d - i - 1]) % m) % m;

        cout << res << '\n';
    }
}
