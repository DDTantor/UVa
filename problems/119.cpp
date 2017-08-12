#include <map>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n, t = 0;
    string G[10];
    while (scanf("%d", &n) != EOF)
    {
        if (t != 0)
            printf("\n");
        t++;
        for (int i = 0; i < n; ++i)
            cin >> G[i];
            
        map<string, int> V;
        for (int i = 0; i < n; ++i)
        {
            string s, p;
            int d, k;
            cin >> s >> d >> k;
            for (int i = 0; i < k; ++i)
            {
                cin >> p;
                V[s] -= d / k;
                V[p] += d / k;
            }
        }
        for (int i = 0; i < n; ++i)
            cout << G[i] << " " << V[G[i]] << '\n';
    }
}
