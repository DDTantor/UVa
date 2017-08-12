#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    int32_t in, out;
    while (cin >> in)
    {
        out = __builtin_bswap32(in);
        if (out >= 4294967296)
            out = ~out;
        cout << in << " converts to " << out << '\n';
    }
}
