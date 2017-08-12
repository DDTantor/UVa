#include <iostream>

using namespace std;

int main()
{
    string s;
    int c = 1;
    while (cin >> s, s != "*")
    {
        cout << "Case " << c++ << ": ";
        if (s == "Hajj")
            cout << "Hajj-e-Akbar\n";
        else
            cout << "Hajj-e-Asghar\n";
    }
}
