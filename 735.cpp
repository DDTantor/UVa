#include <iostream>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
    set<int> tab;
    bool checked[61][61][61];
    for (int j = 1; j <= 3; ++j)
        for (int i = 0; i <= 20; ++i)
            tab.insert(i * j);
    tab.insert(50);            
    int pts;
    vi table(tab.begin(), tab.end());
    int sz = table.size();
    while (cin >> pts, pts > 0)
    {
        int c = 0, p = 0;
        memset(checked, false, sizeof(checked));
        for (int x : table)
        {
            for (int y : table)
            {
                for (int z : table)
                {
                    if (x + y + z == pts)
                    {
                        p++;
                        if (!checked[x][y][z])
                        {
                            c++;
                            checked[x][y][z] = true;
                            checked[x][z][y] = true;
                            checked[y][x][z] = true;
                            checked[y][z][x] = true;
                            checked[z][x][y] = true;
                            checked[z][y][x] = true;
                        }
                    }
                }
            }
        }
        if (c || p)
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << pts << " IS " << c << ".\nNUMBER OF PERMUTATIONS THAT SCORES " << pts << " IS " << p << ".\n";
            
        else
            cout << "THE SCORE OF " << pts << " CANNOT BE MADE WITH THREE DARTS.\n";
        
            cout << "**********************************************************************\n";
        }
    cout << "END OF OUTPUT\n";
}
