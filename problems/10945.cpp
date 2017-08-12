#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s), s != "DONE")
    {
        s.erase(remove_if(s.begin(), s.end(), not1(ptr_fun(::isalpha))), s.end());
        if (equal(s.begin(), s.begin() + s.size()/2, s.rbegin(), [](char a, char b){return tolower(a) == tolower(b);}))
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
    }
}
