#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


char Mapirano(char a)
{
    string A = "ABCDEFGHIJKLMNOPRSTUVWXY";
    for (int i = 0; i < A.size(); ++i)
        if (a == A[i])
            return '0' + i / 3 + 2;
}

string Pretvori(string s)
{
    string a;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == '-')
            continue;
        if (a.size() == 3) 
            a = a + '-';
        if (s[i] < 'A')
            a = a + s[i];
        else
            a = a + Mapirano(s[i]);
    }
    return a;
}

int main()
{
    int t;
    string S[100000];
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> S[i];
        map<string, int> Imenik;
        
        for (int i = 0; i < n; ++i)
            Imenik[Pretvori(S[i])]++;
        if (Imenik.size()==n)
            cout << "No duplicates.\n";
        else
            for (auto i = Imenik.begin(); i != Imenik.end(); ++i)
                if (i->second > 1)
                    cout << i->first << ' ' << i->second << '\n';
        if (t) 
            cout << '\n';
    }
}
