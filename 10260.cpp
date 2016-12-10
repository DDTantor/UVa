#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
    string s, d[6] = {"BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};
    while (cin >> s)
    {
        int bio = -1;
        for (char c : s)
        {
            for (int i = 0; i < 6; ++i)
            {
                if (d[i].find(c) != string::npos)
                {
                    if (bio != i)
                        bio = i, cout << i + 1;
                    break;
                }
                else if (i == 5)
                    bio = -1;
            }
        }
        cout << '\n';
    }
}
