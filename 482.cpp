#include <sstream>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    string p, in;
    int t;
    pair<int, string> A[10000];
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        int n = 0;
        getline(cin, p);
        getline(cin, in);
        istringstream inp(p), iss(in);
        while (iss >> A[n].second, inp >> A[n++].first);
        n--;
        sort(A, A + n);
        for (int i = 0; i < n; ++i)
            cout << A[i].second << '\n';
        if (t)
            cout << '\n';
        cin.ignore(1);
    }
}
