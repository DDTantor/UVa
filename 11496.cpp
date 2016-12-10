#include <iostream>

using namespace std;

int main()
{
    int H[10000], n;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> H[i];
            
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            int r = H[(i + 1) % n];
            int mid = H[i];
            int l = (i)? H[i - 1] : H[n - 1]; 
            if ((mid > r && mid > l) || (mid < r && mid < l))
                cnt++;
        }        
        cout << cnt << '\n';
    }
}
