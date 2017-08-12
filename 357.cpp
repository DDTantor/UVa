#include <iostream>
#include <cstring>

using namespace std;

int cVal[5] = {1, 5, 10, 25, 50};
unsigned long long V[30001];


int main()
{
    int n;
    V[0] = 1;
    for (int i = 0; i < 5; ++i)
        for (int j = cVal[i]; j < 30001; ++j)
            V[j] += V[j - cVal[i]];    
    
    while (cin >> n)
    {
        long long w = V[n];
        if (w == 1)
            cout << "There is only 1 way ";
        else
            cout << "There are " << w << " ways ";

        cout << "to produce " << n << " cents change.\n";
    }
}
