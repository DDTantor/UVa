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

Matrix operator *(Matrix A, Matrix B)
{
    int n = A.dim;
    Matrix C(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
       
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
    ll p, q, n;
    while (cin >> p >> q >> n)
    {
        Matrix X(2);
        X[0][0] = p, X[0][1] = -q, X[1][0] = 1;
        X = X ^ n;
        cout << X[0][0] + X[1][1] << endl;
    }
}
