#include <iostream>

using namespace std;

int main()
{
    int h, w, W[10000];
    while (cin >> h, h)
    {
        cin >> w;
        for (int i = 0; i < w; ++i)
            cin >> W[i];
            
        int total = h - W[0];
        for (int i = 1; i < w; ++i)
            if (W[i - 1] > W[i])
                total += (W[i - 1] - W[i]);
        
        cout << total << '\n';
    }
}
