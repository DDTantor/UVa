#include <iostream>
#include <vector>

using namespace std;

int D[1000][26];

int main()
{
    int n = 0;
    vector<string> W;
    string s;
    while (cin >> s, s != "#")
    {
        for (char c : s)
            ++D[n][c - 'a'];

        ++n;
    }

    cin.ignore();
    while (getline(cin, s), s != "#")
    {
        int freq[26] = {};
        for (char c : s)
            if (c != ' ')
                ++freq[c - 'a'];

        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (freq[i] < D[j][i])
                    break;

                if (i == 25)
                    ++cnt;
            }
        }

        cout << cnt << '\n';
    }
}
