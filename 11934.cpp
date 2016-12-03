#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, L;
    while (cin >> a >> b >> c >> d >> L, a || b || c || d || L)
    {
        int cnt = 0;
        for (int i = 0; i <= L; ++i)
            if (!((a * i * i + b * i + c) % d))
                cnt++;
        
        cout << cnt << '\n';
    }
}
