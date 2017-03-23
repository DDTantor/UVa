#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> Rot90(vector<string>& s, int n)
{
    vector<string> t(n);
    for (int i = 0; i < n; ++i)
    {
        t[i].resize(n);
        for (int j = 0; j < n; ++j)
            t[i][j] = s[n - j - 1][i];
    }
    return t;
}

int main()
{
    int N, n, cnt;
    while (cin >> N >> n, N || n)
    {
        vector<string> S(N), s(n);
        for (int i = 0; i < N; ++i)
            cin >> S[i];
            
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        
        for (int m = 0; m < 4; ++m)
        {    
            cnt = 0;
            for (int i = 0; i <= N - n; ++i)
            {
                for (int j = 0; j <= N - n; ++j)
                {
                    bool flag = true;
                    for (int k = 0; k < n; ++k)
                        for (int l = 0; l < n; ++l)
                            flag &= (S[k + i][l + j] == s[k][l]);
                            
                    cnt += flag;
                }
            }
            if (m)
                cout << ' ';
            cout << cnt;
            s = Rot90(s, n);
        }
        cout << endl;
    }
    
}
