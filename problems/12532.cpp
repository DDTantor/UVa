#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class FenwickTree 
{
    private:
        vi ft;
    public:
        FenwickTree (int n)
        {
            ft.assign(n + 1, 0);
        }
        int rsq(int b)
        {
            int sum = 0;
            for (; b; b -= (b & (-b)))
                sum += ft[b];
            return sum;
        }
        int rsq(int a, int b)
        {
            return rsq(b) - ((a == 1)? 0 : rsq(a - 1));
        }
        void adjust(int k, int v)
        {
            for (; k < ft.size(); k += (k & (-k)))
                ft[k] += v;
        }
};

int main()
{
    int n, k, A[100001];
    while (cin >> n >> k)
    {
        FenwickTree Minus(n);
        FenwickTree Nula(n);
        for (int i = 1; i <= n; ++i)
        {
            cin >> A[i];
            if (A[i] < 0)
                Minus.adjust(i, 1);
            else if (A[i] == 0)
                Nula.adjust(i, 1);
        }
        char c;
        int l, r;
        for (int i = 0; i < k; ++i)
        {
            cin >> c >> l >> r;
            if (c == 'C')
            {
                if ((A[l] >= 0 && r < 0) || (A[l] < 0 && r > 0))
                    Minus.adjust(l, 1);
                else if (A[l] != 0 && r == 0)
                    Nula.adjust(l, 1);
                else if (A[l] == 0 && r != 0)
                    Nula.adjust(l, -1);
                A[l] = r;
            }
            else if (c == 'P')
            {
                int nula = Nula.rsq(l, r);
                int min = Minus.rsq(l, r);
                cout << ((nula)? '0' : ((min % 2)? '-' : '+'));
            }
        }
        cout << '\n';
    }
    
}
