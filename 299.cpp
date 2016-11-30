#include <iostream>

using namespace std;

int main()
{
    int t, T[50];
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> T[i];
        
        int cnt = 0;
        for (int i = 0; i + 1 < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (T[j] < T[i])
                    cnt++;
                                
        cout << "Optimal train swapping takes " << cnt << " swaps.\n";
        
    }
}
