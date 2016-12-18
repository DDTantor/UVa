#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;

#define MP make_pair

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> d;
        vs C(d);
        vii P(d);
        for (int i = 0; i < d; ++i)
        {
            string c;
            int l, h;
            cin >> c >> l >> h;
            C[i] = c;
            P[i] = MP(l, h);
        }
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            string f;
            int cnt = 0, p;
            cin >> p;
            for (int j = 0; j < d; ++j)
                if (P[j].first <= p && P[j].second >= p)
                    cnt++, f = C[j];
            if (cnt == 1)
                cout << f << '\n';
            else
                cout << "UNDETERMINED\n";
        }
        if (t)
            cout << '\n';
    }
}
