#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
    int n;
    while (cin >> n, n)
    {
        string s;
        int m = 0;
        map<vi, int> M;
        for (int i = 0; i < n; ++i)
        {
            vi S(5);
            for (int j = 0; j < 5; ++j)
                cin >> S[j];
               
            sort(S.begin(), S.end());
            M[S]++;
            m = max(m, M[S]);
        }       
        int cnt = 0;
        for (auto it : M)
            if (m == it.second)
                cnt += it.second;
            
        cout << cnt << '\n';
    }
}
