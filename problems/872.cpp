#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

bool A[26], used[26];
int G[26][26], n;
string str, s;
char a, b;
vector<string> sol;

void dfs(int ind)
{
    if (ind == n)
    {
        sol.push_back(str);
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
            str[ind] = i + 'A';
            dfs(ind + 1);
            used[i] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(2);
    while (getline(cin, s), t--)
    {
        n = 0;
        memset(A, false, sizeof(A));
        memset(used, false, sizeof(used));
        memset(G, 0, sizeof(G));
        sol.clear();
        istringstream iss(s);
        while (iss >> a)
            A[a - 'A'] = true, ++n;

        str.resize(n);
        getline(cin, s);
        iss.clear();
        iss.str(s);
        while (iss >> a >> b >> b)
            G[a - 'A'][b - 'A'] = 1;
        
        dfs(0);
        if (sol.empty())
            cout << "NO\n";
        else
        {
            for (int i = 0; i < sol.size(); ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (j)
                        cout << ' ';
                    cout << sol[i][j];
                }
                cout << '\n';
            }
        }
        
        if (cin.peek() != EOF)
            cout << '\n';
        
        cin.ignore();
    }
}
