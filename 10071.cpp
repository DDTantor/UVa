#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int v, t;
    while (scanf("%d %d", &v, &t) != EOF)
        cout << 2 * v * t << '\n';
}
