#include <iostream>
#include <vector>
#include <cstring>

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
    string s;
    int x, y, n, c = 1, A[200001];
    while (cin >> n, n)
    {
        if (c != 1)
            cout << '\n';
        cout << "Case " << c++ << ":\n";
        FenwickTree ft(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> A[i];
            ft.adjust(i, A[i]);
        }
        while (cin >> s, s != "END")
        {
            cin >> x >> y;
            if (s == "S")
                ft.adjust(x, y - A[x]), A[x] = y;
            else if (s == "M")
                cout << ft.rsq(x, y) << '\n';
        }
    }
}
