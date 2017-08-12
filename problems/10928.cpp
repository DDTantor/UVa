#include <iostream>
#include <algorithm>
#include <sstream>
#include <utility>

using namespace std;

typedef pair<int, int> ii;

int Num(string s)
{
    istringstream iss(s);
    int cnt = 0, a;
    while (cnt++, iss >> a);
    return cnt;
}

int main()
{
    ii P[1000];
    int t, N;
    cin >> t;
    while (cin >> N, t--)
    {
        cin.ignore();
        string s;
        for (int i = 0; i < N; ++i)
        {
            getline(cin, s);
            P[i].first = Num(s);
            P[i].second = i + 1;
        }
        sort(P, P + N);
        int min = P[0].first;
        for (int i = 0; i < N && P[i].first == min; ++i)
        {
            if (i)
                cout << ' ' ;
            cout << P[i].second;
        }
        cout << '\n';
    }
    
}
