#include <vector>
#include <iostream>

using namespace std;

typedef vector<long long> vi;
typedef vector<vi> vvi;

struct Matrix
{
    vvi A;
    int dim;
    Matrix() {}
    Matrix(int n) : dim(n) { A.assign(n, vi(n));}
    vi &operator [](int n){ return A[n];}
};

long long n, m, mod;

Matrix operator *(Matrix A, Matrix B)
{
    int n = A.dim;
    Matrix C(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % mod ) % mod;
       
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
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        Matrix F(2);
        mod = 1 << m;
        F[0][0] = F[1][0] = F[0][1] = 1;
        F = F ^ n;
        cout << F[1][0] << '\n';
    }
}
