#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> p;
typedef vector<p > vp;

#define MP make_pair

bool cmp (p a, p b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    int t;
    string s;
    cin >> t;
    cin.ignore();
    vp A;
    for (int i = 0; i < 26; ++i)
        A.push_back(MP(0, 'A' + i));
    while (t--)
    {
        getline(cin, s);
        for (auto i : s)
            if (isalpha(i))
                A[toupper(i) - 'A'].first++;
    }
    sort(A.begin(), A.end(), cmp);
    for (auto i : A)
        if (i.first)
            cout << (char)i.second << ' ' << i.first << '\n';
    
}
