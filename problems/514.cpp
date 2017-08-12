#include <iostream>
#include <stack>

using namespace std;

void Solve(int n)
{
    while(1)
    {
        stack<int> S;
        int c, k = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> c;
            if (c == 0)
                return;
            
            while (k < n && k != c && (S.empty() || S.top() != c))
                S.push(++k);
            
            if (S.top() == c)
                S.pop();
        }
        if (S.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        Solve(n);
        cout << '\n';
    }
}
