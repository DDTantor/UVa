#include <iostream>

using namespace std;

int cVal[5] = {1, 5, 10, 25, 50};
long long V[7490];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    V[0] = 1;
    for (int i = 0; i < 5; ++i)
        for (int j = cVal[i]; j < 7490; ++j)
            V[j] += V[j - cVal[i]];    
    
    while (cin >> n)
        cout << V[n] << '\n';
}
