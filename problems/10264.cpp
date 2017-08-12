#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


int main()
{
    int n, V[1<<15], S[1<<15];
    while (cin >> n)
    {
        for (int i = 0; i < (1 << n); ++i)
            cin >> V[i];
            
        int max = 0;
        for (int i = 0; i < (1 << n); ++i)
        {
            int s = 0;
            for (int j = 1; j < (1 << n); j <<= 1)
                s += V[i ^ j];
                
            S[i] = s;
        }
        int m = 0;
        for (int i = 0; i < (1 << n); ++i)
            for (int j = 1; j < (1 << n); j <<= 1)
                m = (S[i] + S[i ^ j] > m? S[i] + S[i ^ j] : m);
        
        cout << m << '\n';
    }
}
