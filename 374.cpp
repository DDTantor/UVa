#include <iostream>
#include <cstdint>

using namespace std;

int32_t ModulExp(int32_t B, int32_t e, int32_t m)
{
    B %= m;
    int32_t res = 1;
    while (e > 0)
    {
        if (e & 1)
            res = (res * B) % m;
        B = (B * B) % m;
        e >>= 1;
    }
    return res;
}

int main()
{
    int32_t B, P, M;
    while (cin >> B >> P >> M)
        cout << ModulExp(B, P, M) << '\n';
}
