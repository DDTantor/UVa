#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string D[2][6] = {{"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"}, 
                      {"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"}};
    int c = 1;
    while (cin >> s, s != "#")
    {
        int i = 0;
        for (;i < 6; ++i)
            if (D[0][i] == s)
                break;
        
        cout << "Case " << c++ << ": ";
        if (i < 6)
            cout << D[1][i];
        else
            cout << "UNKNOWN";
        
        cout << '\n';
    }
}
