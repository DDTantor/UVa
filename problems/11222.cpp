#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int t, n, c = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << c++ << ":\n";
        vector<vector<int> > F(3);
        int prob[10001], s;
        memset(prob, 0, sizeof(int) * 10001);
        for (int i = 0; i < 3; ++i)
        {
            cin >> s;
            F[i].resize(s);
            for (int j = 0; j < F[i].size(); ++j)
                cin >> F[i][j];
                
            sort(F[i].begin(), F[i].end());
            F[i].erase(unique(F[i].begin(), F[i].end()), F[i].end());
        }
        
        for (int i = 0; i < 3; ++i)
           for (int j = 0; j < F[i].size(); ++j)
                prob[F[i][j]]++;
        
        
        int cnt[3] = {0};
        int max = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < F[i].size(); ++j)
                if (prob[F[i][j]] == 1)
                    cnt[i]++;
            if (cnt[i] > max)
                max = cnt[i];
        }
        for (int i = 0; i < 3; ++i)
        {
            if (cnt[i] == max)
            {
                cout << i + 1 << ' ' << cnt[i];
                for (int j = 0; j < F[i].size(); ++j)
                    if (prob[F[i][j]] == 1)
                        cout << ' ' << F[i][j];
                cout << '\n';
            }
        }
    }
}
