#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

bool A[26], used[26];
int G[26][26], n;
string str;

void dfs(int ind)
{
    if (ind == n)
    {
        cout << str << '\n';
        return;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (A[i] && !used[i])
        {
            for (int j = 0; j < 26; ++j)
                if (G[i][j] == 1 && used[j])
                    return;

            used[i] = true;
            str[ind] = i + 'a';
            dfs(ind + 1);
            used[i] = false;
        }
    }
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        n = 0;
        memset(A, false, sizeof(A));
        memset(used, false, sizeof(used));
        memset(G, 0, sizeof(G));
        istringstream iss(s);
        char a, b;
        while (iss >> a)
            A[a - 'a'] = true, ++n;

        str.resize(n);
        getline(cin, s);
        iss.clear();
        iss.str(s);
        while (iss >> a >> b)
            G[a - 'a'][b - 'a'] = 1;
        dfs(0);
        if (cin.peek() != EOF)
            cout << '\n';
    }
}
