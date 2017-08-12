#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int t, B, SG, SB;
    cin >> t;
    while (cin >> B >> SG >> SB, t--)
    {
        priority_queue<int> L[2];
        int p;
        for (int i = 0; i < SG; ++i)
            cin >> p, L[0].push(p);
            
        for (int i = 0; i < SB; ++i)
            cin >> p, L[1].push(p);
           
        
    
        while (!L[0].empty() && !L[1].empty())
        {
            vector<vector<int> > A(2);
            int m = min(L[0].size(), L[1].size());
            for (int k = 0; k < 2; ++k)                
                for (int i = 0; i < B && i < m; ++i)
                    A[k].push_back(L[k].top()), L[k].pop();
                 
            int size = max(A[0].size(), A[1].size());
            A[0].resize(size);
            A[1].resize(size);
            for (int k = 0; k < size; ++k)
            {
                int res = A[0][k] - A[1][k];
                if (res > 0)
                    L[0].push(res);
                else if (res < 0)
                    L[1].push(-res);
            }
        }
        
        if (L[0].empty() && L[1].empty())
            cout << "green and blue died\n";
        else if (L[0].empty())
        {
            cout << "blue wins\n";
            while (!L[1].empty())
                cout << L[1].top() << '\n', L[1].pop();
        }
        else
        {
            cout << "green wins\n";
            while (!L[0].empty())
                cout << L[0].top() << '\n', L[0].pop();
        }
        if (t)
            cout << '\n';
    }
}
