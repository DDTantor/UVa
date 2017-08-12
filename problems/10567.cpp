#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > vvi;

int main()
{
    string a, b;
    vvi A(256);
    int q;
    cin >> a;
    for (int i = 0; i < a.size(); ++i)
        A[a[i]].push_back(i);
    cin >> q;
    while (q--)
    {
        cin >> b;
        int ind = -1, s = 0;
        bool flag = true;
        for (int i = 0; i < b.size(); ++i)
        {
            auto it = upper_bound(A[b[i]].begin(), A[b[i]].end(), ind);
            ind = it - A[b[i]].begin();
            if (it == A[b[i]].end())
                flag = false;
            ind = A[b[i]][ind];
            if (i == 0)
                s = ind;
        }
        if (flag)
            cout << "Matched " << s << ' ' << ind << '\n';
        else
            cout << "Not matched\n";
    }
    
}
