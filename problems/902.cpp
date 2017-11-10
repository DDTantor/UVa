#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s, sub;
    int n;
    while (cin >> n >> s)
    {
        map<string, int> M;
        for (int i = 0; i < s.size() - n + 1; ++i)
            sub.assign(s, i, n), M[sub]++;

        int best = 0;
        string bests;
        for (auto it : M)
            if (it.second > best)
                best = it.second, bests = it.first;

        cout << bests << '\n';
    }
}
