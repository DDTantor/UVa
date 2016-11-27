#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    long int a, b;
    while (scanf("%ld %ld", &a, &b) != EOF)
        cout << abs(a - b) << '\n';
}
