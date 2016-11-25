#include <string>
#include <iostream>

using namespace std;

int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        string W[10];
        int V[10], max = 0;
        for (int i = 0; i < 10; ++i)
        {
            cin >> W[i] >> V[i];
            if (V[i] > max)
                max = V[i];
        }
        cout << "Case #" << c++ << ":\n";
        for (int i = 0; i < 10; ++i)
            if (V[i] == max)
                cout << W[i] << '\n';        
    }
}
