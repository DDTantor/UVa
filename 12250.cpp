#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string D[2][7] = {{"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE", "UNKNOWN"}, 
                      {"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN", "UNKNOWN"}};
    int c = 1;
    while (cin >> s, s != "#")
    {
        int i = 0;
        for (;i < 6; ++i)
            if (D[0][i] == s)
                break;

        cout << "Case " << c++ << ": " << D[1][i] << '\n';
    }
}
